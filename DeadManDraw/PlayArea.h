#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "CardContainer.h"
class PlayArea : public CardContainer< VectorContainer>
{
public:
	PlayArea();
	~PlayArea();

	bool isBust();

	void moveAllCardsTo(VectorContainer& container);
};


#endif // PLAYAREA_H