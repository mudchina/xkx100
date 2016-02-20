// chui.c 
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(HIC"雷公轰"NOR, ({"leigong hong", "hong", "chui" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 100);
		set("material", "iron");
		set("long", HIC"雷公轰为一柄八角小锤，锤柄长仅及尺，锤头还没常人的拳头大。\n情况紧急时可以掷(zhi)敌。\n"NOR);
		set("wield_msg", HIC"$N将右手伸入左手衣袖，随即将手伸出，手中已握了一柄八角小锤！\n"NOR);
		set("unwield_msg",HIC"$N将手里小锤往袖中一塞就不见了。\n"NOR);
	}
	init_hammer(5);
	setup();
}

void init()
{
	add_action("do_zhi","zhi");
}

int do_zhi(string arg)
{
	object *inv, obj, weapon, me = this_player();
	int attacklvl, dodgelvl, parrylvl, equip;
	string msg;
	object piece;
	
	if (environment(this_object())!=me)
		return 0;
	if(environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗。\n");
	if( (me->is_busy() ))
		return notify_fail("你现在正忙着呢，没得闲掷「雷公轰」。\n");
	if( !(me->is_fighting() ))
		return notify_fail("「雷公轰」只能对战斗中的对手使用。\n");
	if( !arg )
		return notify_fail("你要掷击谁？\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("这里没有这个人！\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
	if( !me->is_fighting(obj) )
		return notify_fail("「雷公轰」只能对战斗中的对手使用。\n");
	if( obj == me ) return notify_fail("掷自己？别想不开啊。\n");
//	obj = me->select_opponent(); 

	attacklvl = me->query_skill("chengzi18po", 1);
	parrylvl = obj->query_skill("parry", 1);
	dodgelvl = obj->query_skill("dodge", 1);
	if( me->query("neili", 1) < 500 )
		return notify_fail("你的内力不足，无力掷出雷公轰！\n");
	if( me->query_skill("qingming-xuangong", 1) < 30 )
		return notify_fail("你的青冥玄功火候不到，无法掷出雷公轰！\n");
	if( attacklvl < 10 )
		return notify_fail("你的城字十八破火候不到，无法掷雷公轰！\n");

	me->add("neili", -200);
	msg = HIY"$N手指一振，八角雷公轰脱手飞出！\n"NOR;

//	if( random(attacklvl) > (int)((parrylvl+dodgelvl)/2))
		if( attacklvl*3/4 > random(parrylvl+dodgelvl))
	{
		inv = all_inventory(obj);
		msg += HIY"$n只觉眼前一股劲风扑来，“轰”的一声！"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
				msg += HIY"一些稀稀拉拉的物事掉在了地上！\n"NOR;
        seteuid(getuid());
        piece = new("/clone/misc/piece");
        piece->set("name",inv[equip]->query("name") + "的碎片");
        piece->set("long", "一堆破碎物事，好象是布片铁片什么的。\n");
        piece->move(environment(obj));
        destruct(inv[equip]);
			}
		}
	}
	else
	{
		msg += HIG "只见$n不慌不忙一侧身，躲过了飞来的雷公轰！\n"NOR;
		if(userp(me)) me->add("neili",-400);
		me->start_busy(4);
	}
	message_vision(msg, me, obj);

	if(userp(obj)) obj->fight_ob(me);
	else if( !obj->is_killing(me) ) obj->kill_ob(me);
//	destruct(this_object());
	this_object()->move(environment(me));
	return 1;
}

