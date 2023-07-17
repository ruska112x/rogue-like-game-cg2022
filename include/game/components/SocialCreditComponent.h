#ifndef INCLUDE_GAME_COMPONENTS_SOCIAL_CREDIT_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_SOCIAL_CREDIT_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class SocialCreditComponent : public IComponent {
 public:
  int social_credits_ = 0;

  explicit SocialCreditComponent(int social_credits) : social_credits_(social_credits) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_SOCIAL_CREDIT_COMPONENT_H_
