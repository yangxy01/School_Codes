#include<iostream>
#include<vector>
#include<string>
#include<time.h>

using namespace std;
struct Jar
{
	int money;
	char role;
};

int BruteForce(vector<Jar>& jars, int role, int left, int right)
{
	int left_money = 0, right_money = 0;
	if (left == right)
	{
		if (role > 0)//角色A,max
		{
			return jars[left].money;
		}
		else
		{
			return -jars[right].money;
		}
	}
	if (role > 0)//角色A,max
	{
		role *= -1;//切换角色
		left_money = BruteForce(jars, role, left + 1, right);
		right_money = BruteForce(jars, role, left, right - 1);
		if (left_money + jars[left].money > right_money + jars[right].money)
		{
			jars[left].role = 'A';
			return left_money + jars[left].money;
		}
		else
		{
			jars[right].role = 'A';
			return right_money + jars[right].money;
		}
	}
	else//角色B,min
	{
		role *= -1;//切换角色
		left_money = BruteForce(jars, role, left + 1, right);
		right_money = BruteForce(jars, role, left, right - 1);
		if (left_money - jars[left].money < right_money - jars[right].money)
		{
			jars[left].role = 'B';
			return left_money - jars[left].money;
		}
		else
		{
			jars[right].role = 'B';
			return right_money - jars[right].money;
		}
	}
}

void Set(vector<Jar>& jars, vector<vector<int>>& record)
{
	int money = 0;
	int num = jars.size();
	int mul = 1;
	if (num % 2 == 0)
		mul *= -1;
	for (int i = 0; i < num; i++)
	{
		record[i][i] = jars[i].money * mul;
	}
	for (int n = 2; n <= num; n++)
	{
		mul *= -1;
		int left = 0, right = left + n - 1;
		while (right < num)
		{
			money = record[left + 1][right] + jars[left].money * mul;
			if (mul > 0)//角色A
			{
				if (record[left][right - 1] + jars[right].money * mul > money)
					money = record[left][right - 1] + jars[right].money * mul;
			}
			else//角色B
			{
				if (record[left][right - 1] + jars[right].money * mul < money)
					money = record[left][right - 1] + jars[right].money * mul;
			}
			record[left][right] = money;
			left++;
			right++;
		}
	}
}

void Set_opt(vector<Jar>& jars, vector<int>& record)
{
	int money = 0;
	int num = jars.size();
	int mul = 1;
	if (num % 2 == 0)
		mul *= -1;
	for (int i = 0; i < num; i++)
	{
		record[i] = jars[i].money * mul;//选右需填补的金罐
		if (i > 0)
			record[i + num] = record[i-1];//选左需填补的金罐
	}
	for (int n = 2; n <= num; n++)
	{
		vector<int> tmp(num * 2);
		mul *= -1;
		int left = 0, right = left + n - 1;
		while (right < num)
		{
			money = jars[left].money * mul + record[right];
			if (mul > 0)//角色A
			{
				if (jars[right].money * mul + record[right + num]> money)
					money = jars[right].money * mul + record[right + num];
			}
			else//角色B
			{
				if (jars[right].money * mul + record[right + num] < money)
					money = jars[right].money * mul + record[right + num];
			}
			tmp[right] = money;
			if(right + 1<num)
				tmp[right+1+num] = money;
			left++;
			right++;
		}
		for (int j = n - 1; j < num; j++)
		{
			record[j] = tmp[j];
			record[j+num] = tmp[j+num];
		}		
	}
}

void callBruteForce()
{
	vector<Jar> jars;
	////jars_1
	//jars.push_back({ 4, 'C' });
	//jars.push_back({ 6, 'C' });
	//jars.push_back({ 2, 'C' });
	//jars.push_back({ 3, 'C' });

	//jars_2
	jars.push_back({ 6, 'C' });
	jars.push_back({ 1, 'C' });
	jars.push_back({ 4, 'C' });
	jars.push_back({ 9, 'C' });
	jars.push_back({ 8, 'C' });
	jars.push_back({ 5, 'C' });

	int left = 0, right = jars.size() - 1;

	int sum = 0;
	int role = 1;
	int diff = BruteForce(jars, role, left, right);
	for (auto x : jars)
	{
		sum += x.money;
	}
	cout << endl;
	int money = (sum + diff) / 2;
	cout << "BruteForce: A max money = " << money <<endl;
}

void showRecord(vector<vector<int>>& record)
{
	for (size_t i = 0; i < record.size(); i++)
	{
		for (size_t j = 0; j < record.size(); j++)
		{
			cout << record[i][j] << " ";
		}
		cout << endl;
	}
}

void callDp(string type="noOpt")
{
	vector<Jar> jars;
	////jars_1
	//jars.push_back({ 4, 'C' });
	//jars.push_back({ 6, 'C' });
	//jars.push_back({ 2, 'C' });
	//jars.push_back({ 3, 'C' });

	//jars_2
	jars.push_back({ 6, 'C' });
	jars.push_back({ 1, 'C' });
	jars.push_back({ 4, 'C' });
	jars.push_back({ 9, 'C' });
	jars.push_back({ 8, 'C' });
	jars.push_back({ 5, 'C' });

	int num = jars.size();
	
	int diff = 0;
	if (type == "opt")
	{
		vector<int> record(num * 2);
		Set_opt(jars, record);
		diff = record[num - 1];
	}
	else
	{
		vector<vector<int>> record(num, vector<int>(num));
		Set(jars, record);
		//showRecord(record);
		diff = record[0][num - 1];
	}	
	int sum = 0;
	for (auto x : jars)
	{
		//cout << x.role << " ";
		sum += x.money;
	}
	int money = (sum + diff) / 2;
	cout << "DP: A max money = " << money << endl;
}

void testBruteForce()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int start = 20, finish = 32;
	for (int scale = start; scale <= finish; scale += 2)
	{
		vector<Jar> jars;
		for (int i = 0; i < scale; i++)
		{
			int num = rand() % 10 + 1;
			jars.push_back({ num, 'C' });
		}
		int left = 0, right = jars.size() - 1;

		int sum = 0;
		int role = 1;
		begin = clock();
		int diff = BruteForce(jars, role, left, right);
		for (auto x : jars)
		{
			sum += x.money;
		}
		cout << endl;
		int money = (sum + diff) / 2;
		cout << "BruteForce: A max money = " << money << endl;
		end = clock();
		time = (double)(end - begin);
		cout << "scale="<<scale<<"  BruteForce耗时：" << time << "ms" << endl;
	}
	
}

void testDP(string type = "noOpt")
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	long start = 22500, finish = 23000;
	for (long scale = start; scale <= finish; scale +=100)
	{
		vector<Jar> jars;
		for (long i = 0; i < scale; i++)
		{
			int num = rand() % 50 + 1;
			jars.push_back({ num, 'C' });
		}
		int num = jars.size();

		int diff = 0;
		if (type == "opt")
		{
			vector<int> record(num * 2);
			begin = clock();
			Set_opt(jars, record);
			diff = record[num - 1];
		}
		else
		{
			vector<vector<int>> record(num, vector<int>(num));
			begin = clock();
			Set(jars, record);
			//showRecord(record);
			diff = record[0][num - 1];
		}
		int sum = 0;
		for (auto x : jars)
		{
			sum += x.money;
		}
		int money = (sum + diff) / 2;
		end = clock();
		time = (double)(end - begin);
		cout << "scale=" << scale << "  DP耗时：" << time << "ms" << endl;

	}

}

int main()
{
	/*callBruteForce();
	callDp("noOpt");*/
	//testBruteForce();
	testDP();
	return 0;
}