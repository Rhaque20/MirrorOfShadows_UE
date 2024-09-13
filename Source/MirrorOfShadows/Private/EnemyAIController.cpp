#include "EnemyAIController.h"
#include "Navigation/CrowdFollowingComponent.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer &ObjectInitializer)
:Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
    
}