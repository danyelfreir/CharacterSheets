CC := g++
CATDIR := obj/Categories
ROLDIR := obj/RoleSpecies
CATEGORIES := $(CATDIR)/Being.o $(CATDIR)/Person.o $(CATDIR)/Investigator.o $(CATDIR)/Creature.o $(CATDIR)/EldritchHorror.o
ROLES := $(ROLDIR)/Role.o $(ROLDIR)/Species.o $(ROLDIR)/RoleSpeciesMap.o $(ROLDIR)/RoleSpeciesHandler.o
OFILES := $(CATEGORIES) $(ROLES) obj/main.o
SRCFILES := src/
INCFILES := inc/
FLAGS := -std=c++11 -I $(INCFILES)
TARGET := CharacterSheets


$(TARGET): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $@

$(OFILES) : obj/%.o : $(SRCFILES)%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OFILES) $(TARGET)
