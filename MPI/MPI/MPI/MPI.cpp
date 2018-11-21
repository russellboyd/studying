//I can't compile any of this because I don't have intel's mpi libs
#include "stdafx.h"
#include <iostream>
using namespace std;

struct Person
{
	string name;
	int age;

	friend class boost::serialization::access;
	template <typename Ar> void serialize(Ar& ar, const unsigned int version)
	{
		ar& name;
		ar& age;
	}
};
int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int size, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
	{
		Person p;
		p.name = "Dmitri";
		p.age = 5000;
		
		ostringstream ofs;
	boost::archive::text_oarchive ar(ofs);
	ar << p;

	auto& s = ofs.str();
	int len = s.length() + 1;
	for (size_t i = 1; i < size; i++)
	{
		MPI_Send(s.c_str(), len, MPI_CHAR, i, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Status status;
		MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
		int count;
		MPI_Get_count(&status, MPI_CHAR, &count);
		cout << "we have " << count;


	}

	/*
	MPI_Init(&argc, &argv);
	int size, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
	{
		cout << "Enter a number: ";
		int n;
		cin >> n;

		for (size_t i = 1; i < size; i++)
		{
			MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		}
	}
	else
	{
		int n;
		MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		cout << n << "^" << rank << " = " << pow(n, rank) << endl;
	}

	MPI_Finalize();
	*/
	return 0;
}