// ���� 19
/*
c++ Ŭ������ ���� ������ ã�ư��� ����� �ȴ�.
����� ���� ��� ���ǰ� �ִ��� �ľ��ϱ�
*/

//���� 20
/*
Cast��� �Լ��� ���� ����ȯ�� �� �� �ִ�.

����)

void AMyActor::NotifyActorOverlap(AActor* OtherActor)
{
	AProjectile* Projectil = Cast<AProjectile>(OtherActor);
	if (Projectil != nullptr)
	{
		//Damage Process
	)
)

�������Ʈ���� ���� �����ϴ�.
*/

//���� 21
/*

������ cpp���Ͽ��� Ȯ��

*/

//���� 22
/*
����)
UENUM(BlueprintType)
enum class EMyColor : uint8
{
	Red UMETA(DisplayName = "Red"),
	Green UMETA(DisplayName = "Green"),
	Blue UMETA(DisplayName = "Blue")
}

���� �� �������� ��� ������ ���̱� �ٶ��ٸ� �װ͵��� ��Ƴ��� ����� ���� ������
*/