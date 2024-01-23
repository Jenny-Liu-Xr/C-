t1: a1-global.o Library.o Date.o Reservation.o Room.o Student.o
	g++ -o t1 a1-global.o Library.o Date.o Reservation.o Room.o Student.o

a1-global.o: a1-global.cc Library.h Date.h
	g++ -c a1-global.cc

Library.o: Library.cc Library.h 
	g++ -c Library.cc

Date.o: Date.cc Date.o
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

Student.o: Student.cc Student.h
	g++ -c Student.cc

clean:
	rm -f *.o t1 a1-global Library Date Reservation Room Student
