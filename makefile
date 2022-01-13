fp: main.o View.o Control.o ReportGenerator.o Record.o RegionAnimalGenerator.o ChangeAnimalGenerator.o SubWithHorseGenerator.o
	g++ -g -o fp main.o View.o Control.o ReportGenerator.o Record.o RegionAnimalGenerator.o ChangeAnimalGenerator.o SubWithHorseGenerator.o

main.o: main.cc Control.h
	g++ -g -c main.cc

View.o: View.cc View.h
	g++ -g -c View.cc

Control.o: Control.cc Control.h View.h RegionAnimalGenerator.h CompareBehaviour.h ReportGenerator.h ChangeAnimalGenerator.h SubWithHorseGenerator.h
	g++ -g -c Control.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Record.h Map.h
	g++ -g -c ReportGenerator.cc

Record.o: Record.cc Record.h
	g++ -g -c Record.cc

RegionAnimalGenerator.o: RegionAnimalGenerator.cc RegionAnimalGenerator.h ReportGenerator.h ReportData.h CompareBehaviour.h
	g++ -g -c RegionAnimalGenerator.cc

ChangeAnimalGenerator.o: ChangeAnimalGenerator.cc ChangeAnimalGenerator.h ReportGenerator.h ReportData.h CompareBehaviour.h
	g++ -g -c ChangeAnimalGenerator.cc

SubWithHorseGenerator.o: SubWithHorseGenerator.cc SubWithHorseGenerator.h ReportGenerator.h ReportData.h CompareBehaviour.h
	g++ -g -c SubWithHorseGenerator.cc

clean:
	rm -f *.o fp
