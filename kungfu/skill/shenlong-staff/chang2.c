// chang2.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "���ɷ�֮���־�"
int perform(object me, object target)
{
	int skill;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

/*	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/	
	fskill = "dulong-dafa";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("���"+to_chinese(fskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if((int)me->query_temp("apply/attack") <= 0 ||
		(int)me->query_temp("apply/dodge") <= 0 ||
		(int)me->query_temp("apply/defense") <= 0)
		return notify_fail("��Ŀǰս����̫�ͣ������ٻָ������ˡ�\n");

	if( (int)me->query_temp("chang") <=-30 )
		return notify_fail("���Ѿ�����̫���ˣ������ٳ��ˡ�\n");

	message_combatd(HIR "ֻ��$N"HIR"���кߺ��������֮���������ǣ�\n" NOR, me);
	me->add_temp("apply/attack", -1);
	me->add_temp("apply/dodge", -1);
	me->add_temp("apply/defense", -1);
	me->add_temp("chang", -1);
	me->add("neili", 100);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��Ĺ�������������
		�����Լ�������

	����Ҫ��
		������70��
		�����ȷ�80��
HELP
	);
	return 1;
}
