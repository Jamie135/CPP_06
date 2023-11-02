#pragma once

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h> //usleep

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
