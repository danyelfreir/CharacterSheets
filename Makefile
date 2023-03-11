CC := g++
CATDIR := obj/categories
ROLDIR := obj/roles
# CATEGORIES := $(CATDIR)/Being.o $(CATDIR)/Person.o $(CATDIR)/Investigator.o $(CATDIR)Creature.o $(CATDIR)EldritchHorror.o
# ROLES := $(ROLDIR)/
OFILES := obj/Being.o obj/Person.o obj/Investigator.o obj/Creature.o obj/EldritchHorror.o obj/Role.o obj/Species.o obj/RoleSpeciesMap.o obj/RoleCreator.o obj/main.o
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
