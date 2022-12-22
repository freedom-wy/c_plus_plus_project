#include <iostream>
using namespace std;

class CPU
{
    public:
        virtual void calculate() = 0;
    
    public:
        virtual ~CPU(){};
};

class VideoCard
{
    public:
        virtual void dispaly() = 0;
    
    public:
        virtual ~VideoCard(){};
};

class Memory
{
    public:
        virtual void storage() = 0;
    public:
        virtual ~Memory(){};
};

class Computer
{
    public:
        Computer(CPU * cpu, VideoCard * vc, Memory * mem)
        {
            c_cpu = cpu;
            c_vc = vc;
            c_mem = mem;
        }

        void work()
        {
            c_cpu->calculate();
            c_vc->dispaly();
            c_mem->storage();
        }

    private:
        // 不能创建抽象类对象，但是可以创建抽象类指针
        CPU * c_cpu;
        VideoCard * c_vc;
        Memory * c_mem;
    
    public:
        ~Computer()
        {
            if (c_cpu != NULL)
            {
                delete c_cpu;
                c_cpu = NULL;
            }
            if (c_vc != NULL)
            {
                delete c_vc;
                c_vc = NULL;
            }
            if (c_mem != NULL)
            {
                delete c_mem;
                c_mem = NULL;
            }
        }
};

class IntelCPU: public CPU
{
    public:
        void calculate()
        {
            cout << "Intel的CPU开始计算" << endl;
        }
};

class IntelMemory: public Memory
{
    public:
        void storage()
        {
            cout << "Intel的内存开始存储了" << endl;
        }
};

class IntelVideoCard: public VideoCard
{
    public:
        void dispaly()
        {
            cout << "Intel的显卡开始显示了" << endl;
        }
};

int main()
{
    //第一台电脑零件
	CPU * intelCpu = new IntelCPU;
	VideoCard * intelCard = new IntelVideoCard;
	Memory * intelMem = new IntelMemory;

	cout << "第一台电脑开始工作：" << endl;
	//创建第一台电脑
	Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
    return 0;
}