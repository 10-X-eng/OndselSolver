#include "pch.h"
#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>
#include <thread>
#include <CADSystem.h>
#include <ASMTAssembly.h>
#include <ASMTPart.h>
#include <GESpMatFullPv.h>
#include <GESpMatParPvMarkoFast.h>
#include <GESpMatParPvPrecise.h>
#include <MomentOfInertiaSolver.h>

using namespace MbD;

TEST(OndselSolver, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runOndselSinglePendulum) {
	//testing::internal::CaptureStdout();
	auto cadSystem = std::make_shared<CADSystem>();
	cadSystem->runOndselSinglePendulum();
	//std::string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runPreDragBackhoe1) {
	auto assembly = ASMTAssembly::assemblyFromFile(std::string(TEST_DATA_PATH) + "/runPreDragBackhoe1.asmt");
	assembly->runDraggingLog(std::string(TEST_DATA_PATH) + "/draggingBackhoe1.log");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runPreDragBackhoe2) {
	auto assembly = ASMTAssembly::assemblyFromFile(std::string(TEST_DATA_PATH) + "/runPreDragBackhoe2.asmt");
	assembly->runDraggingLog(std::string(TEST_DATA_PATH) + "/draggingBackhoe2.log");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runPreDragBackhoe3) {
	auto assembly = ASMTAssembly::assemblyFromFile(std::string(TEST_DATA_PATH) + "/runPreDragBackhoe3.asmt");
	assembly->runDraggingLog(std::string(TEST_DATA_PATH) + "/draggingBackhoe3.log");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, pistonAllowZRotation) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/pistonAllowZRotation.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, RevRevJt) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/RevRevJt.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, RevCylJt) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/RevCylJt.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, CylSphJt) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/CylSphJt.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, SphSphJt) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/SphSphJt.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, Gears) {
	ASMTAssembly::readWriteFile(std::string(TEST_DATA_PATH) + "/Gears.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, anglejoint) {
	ASMTAssembly::readWriteFile(std::string(TEST_DATA_PATH) + "/anglejoint.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, constvel) {
	ASMTAssembly::readWriteFile(std::string(TEST_DATA_PATH) + "/constvel.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, rackscrew) {
	ASMTAssembly::readWriteFile(std::string(TEST_DATA_PATH) + "/rackscrew.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, planarbug) {
	ASMTAssembly::readWriteFile(std::string(TEST_DATA_PATH) + "/planarbug.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, cirpendu2) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/cirpendu2.asmt");	//Under constrained. Testing ICKine.
	EXPECT_TRUE(true);
}
TEST(OndselSolver, quasikine) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/quasikine.asmt");	//Under constrained. Testing ICKine.
	EXPECT_TRUE(true);
}
TEST(OndselSolver, piston) {
	ASMTAssembly::readWriteFile(std::string(TEST_DATA_PATH) + "/piston.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runSinglePendulumSuperSimplified) {
	ASMTAssembly::runSinglePendulumSuperSimplified();	//Mass is missing
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runSinglePendulumSuperSimplified2) {
	ASMTAssembly::runSinglePendulumSuperSimplified2();	//DOF has infinite acceleration due to zero mass and inertias
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runSinglePendulumSimplified) {
	ASMTAssembly::runSinglePendulumSimplified();
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runSinglePendulum) {
	ASMTAssembly::runSinglePendulum();
	EXPECT_TRUE(true);
}
TEST(OndselSolver, piston2) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/piston.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, 00backhoe) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/00backhoe.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, circular) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/circular.asmt");	//Needs checking
	EXPECT_TRUE(true);
}
TEST(OndselSolver, engine1) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/engine1.asmt");	//Needs checking
	EXPECT_TRUE(true);
}
TEST(OndselSolver, fourbar) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/fourbar.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, fourbot) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/fourbot.asmt");	//Very large but works
	EXPECT_TRUE(true);
}
TEST(OndselSolver, wobpump) {
	ASMTAssembly::runFile(std::string(TEST_DATA_PATH) + "/wobpump.asmt");
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runOndselDoublePendulum) {
	auto cadSystem = std::make_shared<CADSystem>();
	cadSystem->runOndselDoublePendulum();
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runOndselPiston) {
	auto cadSystem = std::make_shared<CADSystem>();
	cadSystem->runOndselPiston();		//For debugging
	EXPECT_TRUE(true);
}
TEST(OndselSolver, runPiston) {
	auto cadSystem = std::make_shared<CADSystem>();
	cadSystem->runPiston();
	EXPECT_TRUE(true);
}
TEST(OndselSolver, GESpMatParPvPrecise) {
	GESpMatParPvPrecise::runSpMat();
	EXPECT_TRUE(true);
}
TEST(OndselSolver, GESpMatFullPvBackSubstitutionUsesLastValidIndex) {
	auto matrix = std::make_shared<SparseMatrix<double>>(2, 2);
	matrix->atijput(0, 0, 2.0);
	matrix->atijput(0, 1, 1.0);
	matrix->atijput(1, 0, 1.0);
	matrix->atijput(1, 1, 3.0);
	auto rightHandSide = std::make_shared<FullColumn<double>>(2);
	rightHandSide->atiput(0, 5.0);
	rightHandSide->atiput(1, 7.0);

	auto solver = std::make_shared<GESpMatFullPv>();
	auto answer = solver->solvewithsaveOriginal(matrix, rightHandSide, true);

	ASSERT_EQ(answer->size(), 2);
	EXPECT_NEAR(answer->at(0), 1.6, 1.0e-12);
	EXPECT_NEAR(answer->at(1), 1.8, 1.0e-12);
}
TEST(OndselSolver, SparseSolverParallelExecutorPreservesSolution) {
	constexpr size_t dimension = 24;
	auto matrix = std::make_shared<SparseMatrix<double>>(dimension, dimension);
	auto rightHandSide = std::make_shared<FullColumn<double>>(dimension);
	for (size_t row = 0; row < dimension; ++row) {
		matrix->atijput(row, row, 4.0);
		double value = 4.0 * static_cast<double>(row + 1);
		if (row > 0) {
			matrix->atijput(row, row - 1, -1.0);
			value -= static_cast<double>(row);
		}
		if (row + 1 < dimension) {
			matrix->atijput(row, row + 1, -1.0);
			value -= static_cast<double>(row + 2);
		}
		rightHandSide->atiput(row, value);
	}

	std::atomic_size_t executorCalls {0};
	std::atomic_size_t active {0};
	std::atomic_size_t maximumActive {0};
	auto solver = std::make_shared<GESpMatParPvMarkoFast>();
	solver->setParallelExecutor(
		[&](size_t count, const std::function<void(size_t)>& work) {
			executorCalls.fetch_add(1, std::memory_order_relaxed);
			std::mutex gateMutex;
			std::condition_variable gateChanged;
			size_t arrived = 0;
			std::vector<std::future<void>> tasks;
			tasks.reserve(count);
			for (size_t index = 0; index < count; ++index) {
				tasks.push_back(std::async(std::launch::async, [&, index] {
					const auto now = active.fetch_add(1, std::memory_order_relaxed) + 1;
					auto observed = maximumActive.load(std::memory_order_relaxed);
					while (observed < now
					       && !maximumActive.compare_exchange_weak(
						   observed,
						   now,
						   std::memory_order_relaxed
					       )) {}
					{
						std::unique_lock lock(gateMutex);
						++arrived;
						if (arrived == count) {
							gateChanged.notify_all();
						}
						else {
							gateChanged.wait(lock, [&] { return arrived == count; });
						}
					}
					work(index);
					active.fetch_sub(1, std::memory_order_relaxed);
				}));
			}
			for (auto& task : tasks) {
				task.get();
			}
		}
	);

	auto answer = solver->solvewithsaveOriginal(matrix, rightHandSide, true);

	ASSERT_EQ(answer->size(), dimension);
	for (size_t index = 0; index < dimension; ++index) {
		EXPECT_NEAR(answer->at(index), static_cast<double>(index + 1), 1.0e-10);
	}
	EXPECT_GT(executorCalls.load(std::memory_order_relaxed), 0);
	EXPECT_GT(maximumActive.load(std::memory_order_relaxed), 1);
}
TEST(OndselSolver, KinematicSimulationUsesHostExecutorAndPreservesEveryPose) {
	auto serial = ASMTAssembly::assemblyFromFile(std::string(TEST_DATA_PATH) + "/fourbar.asmt");
	auto dispatched = ASMTAssembly::assemblyFromFile(std::string(TEST_DATA_PATH) + "/fourbar.asmt");
	// This fixture contains historical timestamps. Exercise a fresh solve,
	// as the host does, rather than appending to its stored time series.
	serial->times->clear();
	dispatched->times->clear();
	size_t calls = 0;
	dispatched->setParallelExecutor([&](size_t count, const ParallelIndexWork& work) {
		++calls;
		for (size_t index = 0; index < count; ++index) work(index);
	});
	serial->runKINEMATIC();
	dispatched->runKINEMATIC();
	EXPECT_GT(calls, 0);
	ASSERT_GT(serial->numberOfFrames(), 2);
	ASSERT_EQ(serial->numberOfFrames(), dispatched->numberOfFrames());
	ASSERT_EQ(serial->parts->size(), dispatched->parts->size());
	for (size_t frame = 0; frame < serial->numberOfFrames(); ++frame) {
		for (size_t part = 0; part < serial->parts->size(); ++part) {
			auto first = serial->parts->at(part);
			auto second = dispatched->parts->at(part);
			auto position = first->getPosition3D(frame);
			auto otherPosition = second->getPosition3D(frame);
			auto rotation = first->getRotationMatrix(frame);
			auto otherRotation = second->getRotationMatrix(frame);
			for (size_t row = 0; row < 3; ++row) {
				EXPECT_NEAR(position->at(row), otherPosition->at(row), 1.0e-9);
				for (size_t column = 0; column < 3; ++column) {
					EXPECT_NEAR(rotation->at(row)->at(column), otherRotation->at(row)->at(column), 1.0e-9);
				}
			}
		}
	}
}
TEST(OndselSolver, KinematicSimulationHonorsCancellationBetweenFrames) {
	auto assembly = ASMTAssembly::assemblyFromFile(std::string(TEST_DATA_PATH) + "/fourbar.asmt");
	assembly->times->clear();
	struct Cancelled : std::runtime_error {
		Cancelled() : std::runtime_error("Host cancelled simulation") {}
	};
	size_t checks = 0;
	assembly->setCancellationCheck([&] {
		++checks;
		if (assembly->numberOfFrames() >= 3) throw Cancelled {};
	});
	EXPECT_THROW(assembly->runKINEMATIC(), Cancelled);
	EXPECT_GT(checks, 0);
	EXPECT_EQ(assembly->numberOfFrames(), 3);
}
TEST(OndselSolver, MomentOfInertiaSolver) {
	MomentOfInertiaSolver::example1();
	EXPECT_TRUE(true);
}
TEST(OndselSolver, sharedptrTest) {
	auto assm = ASMTAssembly::With();

	std::shared_ptr<ASMTAssembly> assm1 = assm;	//New shared_ptr to old object. Reference count incremented.
	assert(assm == assm1);
	assert(assm.get() == assm1.get());
	assert(&assm != &assm1);
	assert(assm->constantGravity == assm1->constantGravity);
	assert(&(assm->constantGravity) == &(assm1->constantGravity));

	auto assm2 = std::make_shared<ASMTAssembly>(*assm);	//New shared_ptr to new object. Member variables copy old member variables
	assert(assm != assm2);
	assert(assm.get() != assm2.get());
	assert(&assm != &assm2);
	assert(assm->constantGravity == assm2->constantGravity);	//constantGravity is same object pointed to
	assert(&(assm->constantGravity) != &(assm2->constantGravity)); //Different shared_ptrs of same reference counter
	EXPECT_TRUE(true);
}
