#include <iostream>
using namespace std;


/*
��C++�У����ࡢ�����ͱ�����������ѭһ����Լ�������ʵ������ȷ������������Ϳ�ά���ԡ�������һЩ����������������

1. **������**��
   - ʹ���շ���������CamelCase��������ÿ�����ʵ�����ĸ��д�����磺`MyClass`, `AudioProcessor`��
   - ����Ӧ�������ʻ����ʶ�������ر�����Ĺ��ܻ����ԡ�

2. **��������**��
   - ͨ��Ҳʹ���շ���������������ĸСд�����磺`calculateTotal`, `readFromFile`��
   - ������Ӧ���Ƕ��ʻ򶯴ʶ��׼ȷ������������Ϊ�������
   - ���ڷ�������getter�����޸�����setter��������ͨ��ʹ��`get`��`set`��Ϊǰ׺�����磺`getAge`, `setName`��

3. **��������**��
   - ������ͨ��ʹ��Сд��ĸ������֮�����»��߷ָ������Ϊ������������snake_case�������磺`current_speed`, `file_name`��
   - ������Ӧ�þ��������ԣ�ʹ�������������ܹ��������;��
   - ����ȫ�ֱ�������ĳ�Ա��������ʱ��ʹ���ض���ǰ׺���׺����`g_`��`m_`�����֡����磺`g_globalCounter`, `m_memberData`��

4. **�����ͺ�����**��
   - �����ͺ�ͨ��ʹ��ȫ��д��ĸ������֮�����»��߷ָ������磺`MAX_HEIGHT`, `DEFAULT_VALUE`��

5. **ģ�����Ͳ�������**��
   - ģ�����Ͳ���ͨ��ʹ�ô�д��ĸ����`T`, `U`, `V`�����߸��������Ե����ƣ���`KeyType`, `ValueType`��

��ס����Щֻ��ָ��ԭ�򣬲�ͬ����Ŀ���Ŷӿ��ܻ����Լ�������Լ������Ҫ������������Ŀ�б���һ���ԡ�
*/


// Ĭ�Ϲ���Ϳ���������ͬ



// ��������
/*
(1)���һ����Aû�п������캯�������Ǻ���һ��������CTB�ĳ�Ա����m_ctb��������CTB���п������캯������ô�����������漰����A�Ŀ�������ʱ���������ͻ�Ϊ��A�ϳ�һ���������캯����
�������ϳɵĿ������캯���������Ǹ�һЩ��������顣���ֻ��һЩ���Ա����ֵ�Ŀ�����Щ�£��������ǲ���ר�źϳɳ��������캯�����ɵģ��������ڲ��͸��ˣ�
(2)���һ����CTBSonû�п������캯������������һ������CTB�������п������캯����
�����������漰����CTBSon�Ŀ�������ʱ����������ΪCTBSon�ϳ�һ���������캯�� �����ø���Ŀ�
(3)���һ����CTBSonû�п������캯�������Ǹ��������˻��߼̳����麯���������������漰����CTBSon�Ŀ�������ʱ����������ΪCTBSon�ϳ�һ���������캯�� ,������������캯���������䣺
������ĺ��� ���趨�����myctbson2���麯����ָ��ֵ���麯����ָ�룬�麯����ȸ���
(4)��� һ����û�п������캯���� ���Ǹ��ຬ������൱���������漰����Ŀ�������ʱ����������Ϊ����ϳ�һ���������캯����
�����������漰�ɿ�������ȥ����һ������ʱ��������麯�������Ա������࣬���࿽�����캯��������������Ҫ����ʱ���ͻ�����Ĭ�ϵĿ������캯����
*/





// �޼̳й�ϵ��������
class AClass
{
public:
	int a_number;
public:
	// ��AClass�в�дĬ�Ϲ��췽��,�򲻻ᴴ��Ĭ�Ϲ��췽��, ��д�˹��췽��,���ڴ�����ʱ��ᴴ�����췽��
	AClass()
	{
		this->a_number = 0;
		cout << "AClass��Ĭ�Ϲ��췽��" << endl;
	}
	AClass(int number)
	{
		this->a_number = number;
	}
};

class BClass
{
	// ��AClass��д��Ĭ�Ϲ��췽��������BClass�н����˵���,�������AClass��Ĭ�Ϲ����BClass��Ĭ�Ϲ���
public:
	int b_number;
	AClass a1;
};

// �м̳й�ϵ
class CClass
{
public:
	int c_number;
public:
	CClass()
	{
		cout << "Ĭ�Ϲ��췽��" << endl;
		this->c_number = 0;
	}
	CClass(int number)
	{
		cout << "�вι��췽��" << endl;
		this->c_number = number;
	}
};

class DClass: public CClass
{
	// ���̳�,��������Ϊ��������Ĭ�Ϲ��췽��
};

class EClass
{
	// ���������麯��ʱ,������Ĭ�Ϲ���
	virtual void eclassFunction()
	{
		cout << "�麯�������" << endl;
	}
};

class FClass
{
	// δ������������
public:
	int f_number;
};

class GClass
{
public:
	FClass f; // ��ʹ�ڳ�Ա������ʹ����FClassҲδ������������
	int g_number;
};

class HClass
{
public:
	int h_number;
	HClass()
	{
		this->h_number = 0;
		cout << "HClassĬ�Ϲ��췽��" << endl;
	}
	HClass(int number)
	{
		cout << "HClassĬ���вη���" << endl;
		this->h_number = number;
	}
	HClass(const HClass& obj) // д������������ҪдĬ�Ϲ���
	{
		this->h_number = obj.h_number;
		cout << "HClass�Ŀ������췽��" << endl;
	}
};

class IClass
{
public:
	HClass h;
};




int main()
{
	/*IClass* i1 = new IClass();
	i1->h.h_number = 1;
	IClass* i2 = i1;
	cout << "h_number��ֵΪ: " << i2->h.h_number << endl;
	cout << "==============" << endl;*/
	IClass i3;
	i3.h.h_number = 3;
	IClass i4 = i3;
	cout << "h_number��ֵΪ: " << i4.h.h_number << endl;
	return 0;
}

/*AClass* a = new AClass();
	a->a_number = 1;
	delete a;*/
	/*BClass* b = new BClass();
	delete b;*/
	/*CClass* c = new CClass();
	delete c;*/
	/*EClass* e = new EClass();
	delete e;*/
	/*FClass* f1 = new FClass();
	f1->f_number = 1;
	FClass* f2 = f1;
	cout << "f_number��ֵΪ: " << f2->f_number << endl;*/
	/*GClass* g1 = new GClass();
	g1->g_number = 2;
	g1->f.f_number = 3;
	GClass* g2 = g1;
	cout << "f_number��ֵΪ: " << g2->f.f_number << ", g_number��ֵΪ: " << g2->g_number << endl;*/