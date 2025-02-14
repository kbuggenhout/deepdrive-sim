
#pragma once

#include "Simulation/Agent/DeepDriveAgentControllerBase.h"
#include "DeepDriveAgentManualController.generated.h"

class ADeepDriveSplineTrack;

USTRUCT(BlueprintType)
struct FDeepDriveManualControllerConfiguration
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Control)
	FString		ConfigurationName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Control)
	ADeepDriveSplineTrack	*Track;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Control)
	TArray<float>	StartDistances;

};


/**
 * 
 */
UCLASS()
class DEEPDRIVEPLUGIN_API ADeepDriveAgentManualController : public ADeepDriveAgentControllerBase
{
	GENERATED_BODY()
	
public:

	ADeepDriveAgentManualController();

	virtual bool Activate(ADeepDriveAgent &agent, bool keepPosition);

	virtual bool ResetAgent();

	virtual void MoveForward(float axisValue);

	virtual void MoveRight(float axisValue);

	virtual void Brake(float axisValue);

	UFUNCTION(BlueprintCallable, Category = "Configuration")
	void Configure(const FDeepDriveManualControllerConfiguration &Configuration, int32 StartPositionSlot, ADeepDriveSimulation* DeepDriveSimulation);

private:

};
