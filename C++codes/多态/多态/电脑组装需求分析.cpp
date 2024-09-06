#include <iostream>
using namespace std;

class CPU
{
public:
	// abstract calculate function
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	// abstract display function
	virtual void display() = 0;
};

class Memory
{
public:
	// abstract storage function
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	~Computer()
	{
		cout << "Computer destructor call" << endl;

		// release cpu part
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		// release vc part
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}

		// release memory part
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel的CPU开始计算了" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Intel的显卡开始显示了" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel的内存开始存储了" << endl;
	}
};

class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo的CPU开始计算了" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo的显卡开始显示了" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo的内存开始存储了" << endl;
	}
};

void test()
{
	// Creating components for the first computer
	CPU* cpu = new IntelCPU;
	VideoCard* vc = new IntelVideoCard;
	Memory* mem = new IntelMemory;

	// Creating the first computer using the components
	Computer* computer1 = new Computer(cpu, vc, mem);
	computer1->work();

	// Release the memory allocated for the first computer to avoid memory leaks
	delete computer1;

	cout << "----------------------" << endl;

	// Creating the components for the second computer directly within the constructor call
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();

	// Release the memory allocated for the second computer
	delete computer2;

	cout << "----------------------" << endl;

	// Creating the components for the third computer directly within the constructor call
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->work();

	// Release the memory allocated for the third computer
	delete computer3;
}

int main()
{
	test();
	return 0;
}