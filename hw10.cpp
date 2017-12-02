//Steven Ferrarese
//COS 221
//11/29/2017
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
void print(int [][2], int);
void find(int [][2], int, int ,int, int,string);
void addNode(string);
string toStr(int);
vector <string> results;
int toint(string);
int main()
{
	cout << "Steven Ferrarese COS 221 "<<endl;
	int vertices  = 6;
	int vert [][2] =  
	{{0,1},{0,2},
	{1,0},{1,3},
	{2,0},{2,3},{2,4},
	{3,1},{3,2},{3,4},{3,5},
	{4,2},{4,3},{4,5},
	{5,3},{5,4}};	 
	
	int start, end;//enter input
	cout << "Enter Start and end vertice : ";
	string ss;
	getline(cin, ss);
	end = toint(ss.substr(2));
	start = toint(ss.substr(0));	
	//start = ss/100;
	//end = start *100 - ss;
	
	find(vert,vertices,end,0,0,toStr(start));
	string shortest = ""; 
	int l = 0,t = 9999999;
	for (int i = 0 ; i < results.size(); i++)//find how short the shortest paths are
	{
		l = results.at(i).size();
		if (l <= t )
		{	
			t = l;
		}
	}
	int x = 1;
	for (int i = 0; i < results.size();i++)//print out how many shortest paths their are
	{
		if (results.at(i).size() == t)
		{
			cout << "The shortest path #"<<(x++)<<" : "<<results.at(i)<<endl; 
		}	
	}
	
	print(vert, vertices);
	return 0;
}
void  find (int vert[][2], int vertices, int end, int dd, int prev, string node)//tree search type thing I wrote
{
	int x = 0, current = 0;
	int yy = 0,i;
	
	while (vert[current][0] != dd)//get current to the position of the current vertice
	{
		current ++;	
	}
	while (vert[current][0]==vert[current +1][0])//finding how many things connect to this vertice
	{	
		if (vert[current+1][1]== end)//if we find the vertice we are looking for add to the current node list
		{ 	node = node + " " + toStr(vert[current+1][1]);
			addNode(node);
			return ;	
		}
		yy++;
		current ++;
	}
	string tmp = "";
	current  = current -yy;//get use back to the right position
	for (i = 0 ; i <= yy; i++)
	{	
		tmp = "";
		if (vert[current][1]!= prev)//to make sure we dont got backwards !
		{
			tmp = node + " " +toStr(vert[current][1]); 	
			
			find(vert,vertices,end,vert[current][1],dd,tmp);//use recursion to go down the node/tree
			// go down a vertice that the current vertice is connect to  
			
		}
		current ++;
	}
	return ;
}
int toint(string c)
{
	stringstream str;
	str << c;
	int x;
	str >> x;
	return x;
}
void addNode(string node)//found node so we add to list
{
	results.push_back(node);
}
string toStr(int x)//convert int to a string so can add to the string of nodes
{
	stringstream ss;
	ss << x;
	return ss.str();

}
void print(int vert[][2], int x)//print them all out
{	
	cout << "The number of vertices is "<<x<< endl;
	int i = 0,j, count = 0, num = 0;
	for(i = 0; i < x; i++)
	{
		cout << "Vertex "<< i << ": "<<vert[i][1]; 
		j = 0;
		num =0;	
		while (vert[count][0] == vert[count+1][0])
		{
			num ++;
			count ++;
		}
		count = count - num;
		for (int y = 0;y <= num ;y++)
		{
			cout << "(" << i << ", "<< vert[count][1] <<") ";
			j++;
			count ++;
		}
		//cout << "(" << i  << ", "<<vert[count][1]<<") ";
		//count ++;
		cout << endl;
	}

}
