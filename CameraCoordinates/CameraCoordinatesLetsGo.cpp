#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
int main()
{   
	int count = 0;
	float alpha = 45;
	float x = 0, y = 0, x1 = 0, y1 = 0;
	char buff[250] = { 0 };
	char xNumeral[10] = { 0 };
	char yNumeral[10] = { 0 };
	string temp; 
	ofstream file("save.json");
	ifstream fout("file.json");
	while (!fout.eof())
	{
		fout.getline(buff, 250, '\n');
		if (buff[0] == '{')
		{
			char* define;
			if (strstr(buff, "bus") != NULL)
			{
				temp = "bus";
			}
			else if (strstr(buff, "truck") != NULL)
			{
				temp = "truck";
			}
			else if (strstr(buff, "person") != NULL)
			{
				temp = "person";
			}
			else
			{
				temp = "car";
			}
			char* point = strstr(buff, "x_coor");
			point += 9;
			while (*point != ',')
			{
				xNumeral[count] = *point;
				count++;
				point++;
			}
			xNumeral[count + 1] = NULL;
			count = 0;
			x = stof(xNumeral);

			point = strstr(buff, "y_coor");
			point += 9;
			while (*point != '}')
			{
				yNumeral[count] = *point;
				count++;
				point++;
			}
			yNumeral[count + 1] = NULL;
			count = 0;
			y = stof(yNumeral);

			x1 = (cos(alpha) * x + (-sin(alpha) * y));
			y1 = (sin(alpha) * x + cos(alpha) * y);

			ofstream out("save.json", ios::app);
			if (out.is_open())
			{
				out << temp << "," << x1 << "," << y1 << endl;
			}
			out.close();
		}
		else
		{
			ofstream out("save.json", ios::app);
			if (out.is_open())
			{
				out  << endl;
			}
			out.close();
		}
	}
	fout.close();

}

 