

tycoon.out: main.o Game.o Player.o PropertiesList.o Property.o Apartment.o House.o Business.o Tenant.o Civilian_Tenant.o Business_Tenant.o
	$(CXX) $(CXXFLAGS) -o tycoon.out main.o Game.o Player.o PropertiesList.o Property.o Apartment.o House.o Business.o Tenant.o Civilian_Tenant.o Business_Tenant.o

main.o: main.cpp Core/Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Core/Game.cpp Core/Player.h Properties/Property.h Core/PropertiesList.h
	$(CXX) $(CXXFLAGS) -c Core/Game.cpp 

Player.o: Core/Player.cpp Core/PropertiesList.h
	$(CXX) $(CXXFLAGS) -c Core/Player.cpp

PropertiesList.o: Core/PropertiesList.cpp Properties/Property.h
	$(CXX) $(CXXFLAGS) -c Core/PropertiesList.cpp

Property.o: Properties/Property.cpp Tenants/Tenant.h Properties/Apartment.h Properties/House.h Properties/Business.h
	$(CXX) $(CXXFLAGS) -c Properties/Property.cpp

Apartment.o: Properties/Apartment.cpp Properties/Property.h
	$(CXX) $(CXXFLAGS) -c Properties/Apartment.cpp

House.o: Properties/House.cpp Properties/Property.h
	$(CXX) $(CXXFLAGS) -c Properties/House.cpp

Business.o: Properties/Business.cpp Properties/Property.h
	$(CXX) $(CXXFLAGS) -c Properties/Business.cpp

Tenant.o: Tenants/Tenant.cpp
	$(CXX) $(CXXFLAGS) -c Tenants/Tenant.cpp

Civilian_Tenant.o: Tenants/Civilian_Tenant.cpp Tenants/Tenant.h
	$(CXX) $(CXXFLAGS) -c Tenants/Civilian_Tenant.cpp

Business_Tenant.o: Tenants/Business_Tenant.cpp Tenants/Tenant.h
	$(CXX) $(CXXFLAGS) -c Tenants/Business_Tenant.cpp

yeet:
	rm *.o