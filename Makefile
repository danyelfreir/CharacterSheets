CC := g++
CATDIR := obj/categories
ROLDIR := obj/roles
CATEGORIES := $(CATDIR)/Being.o $(CATDIR)/Person.o $(CATDIR)/Investigator.o $(CATDIR)Creature.o $(CATDIR)EldritchHorror.o
ROLES := $(ROLDIR)/
OFILES := obj/main.o
SRCFILES := src/
INCFILES := inc/
FLAGS := -std=c++11 -I $(INCFILES)
TARGET := CharacterSheets


$(TARGET): $(CATEGORIES) $(ROLES) $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $@

$(OFILES) : obj/%.o : $(SRCFILES)%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OFILES) $(CATEGORIES) $(ROLES) $(TARGET)
