#include <utils/lu_thread.h>

using namespace lu;

LU_Thread::LU_Thread()
{
	is_running_ = false;
}

LU_Thread::~LU_Thread()
{
};

LU_Thread* 
LU_Thread::start()
{
	if (is_running_) 
		return this;

	is_running_ = true;
	thread_ = std::make_shared<std::thread>(&LU_Thread::threadEntry, this);

	return this;
}

std::shared_ptr<std::thread> 
LU_Thread::getThreadControl()
{
	return thread_;
}
bool 
LU_Thread::isAlive() const
{
	return is_running_;
}

void 
LU_Thread::threadEntry(LU_Thread *pThread)
{
	pThread->run();
}