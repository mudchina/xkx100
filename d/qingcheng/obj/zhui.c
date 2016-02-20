// zhui.c 
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(HIC"铁锥"NOR, ({ "tie zhui", "zhui" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("count", 12);
                set("value", 100);
                set("material", "iron");
                set("long", HIC"此铁锥长六七寸许，锥尖曲了两曲。里面共有"+chinese_number(query("count"))+"支青蜂钉可以射出(shoot)。\n"NOR);
                set("wield_msg", HIC"$N将左手伸入右手衣袖，随即将手伸出，手中已握了一柄铁锥！\n"NOR);
                set("unwield_msg",HIC"$N将手里铁锥往袖中一塞就不见了。\n"NOR);
        }
        init_dagger(5);
        setup();
}

void init()
{
	add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
	object weapon, obj, me = this_player();
	int attacklvl, dodgelvl, parrylvl, damage;

	if (environment(this_object())!=me)
		return 0;
	if(environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗。\n");
	if( (me->is_busy() ))
		return notify_fail("你现在正忙着呢，没得闲用「青蜂钉」。\n");
	if( !arg )
		return notify_fail("你要射击谁？\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("这里没有这个人！\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
	if( !me->is_fighting(obj) )
		return notify_fail("「青蜂钉」只能对战斗中的对手使用。\n");
	if( obj == me ) return notify_fail("射自己？别想不开啊。\n");
//	obj = me->select_opponent();

	if( query("count") == 0 )
		return notify_fail("青蜂钉都射光了，收手罢。\n");
	attacklvl = me->query_skill("qingzi9da", 1);
	parrylvl = obj->query_skill("parry", 1);
	dodgelvl = obj->query_skill("dodge", 1);
	damage = obj->query("eff_qi");
	if( me->query("neili") < 400 )
		return notify_fail("你的内力不足，无力发出青蜂钉！\n");
	if( me->query_skill("qingming-xuangong", 1) < 30 )
		return notify_fail("你的青冥玄功火候不到，无法发出青蜂钉！\n");
	if( attacklvl < 10 )
		return notify_fail("你的青字九打火候不到，无法发出青蜂钉！\n");

	add("count", -1);
	me->add("neili", -300);
	weapon = new(__DIR__"qingfengding");
/* 发射 */
	if( attacklvl < 40 )
	{
		message_vision(HIG"$N在铁锥后部一敲，一支青蜂钉疾速射出！\n"NOR, me);
	}
	else
		if( attacklvl < 70 )
		{
			message_vision(HIG"$N在铁锥后部一敲，一支青蜂钉呼啸而出！\n"NOR, me);
		}
		else
			if( attacklvl < 100 )
			{
				message_vision(HIG"$N在铁锥后部一敲，一支青蜂钉破空射出！\n"NOR, me);
			}
			else
			{
				message_vision(HIG"$N在铁锥后部一敲，一支青蜂钉电射而出！\n"NOR, me);
			}

	if(userp(obj)) obj->kill_ob(me);
	else obj->fight_ob(me);

	me->start_busy(2);
/* 不中 */

	if( attacklvl < (int)(dodgelvl/2) + random((int)(dodgelvl/2)) )
	{
		weapon->move(obj);
		message_vision(HIY"$N冷笑一声，伸出脚丫子只一夹，轻松刁住了青蜂钉。\n"NOR, obj);
		return 1;
	}
//	if( attacklvl < (int)(dodgelvl/2) + random(parrylvl))
	if( attacklvl < random(dodgelvl) + random(parrylvl))
	{
		weapon->move(environment(me));
		message_vision(HIY"$N一声冷哼，抬手声食指一弹，正好弹在青蜂钉上，青蜂钉一闪落地！\n"NOR, obj);
		return 1;
	}
	if( attacklvl < (int)(parrylvl/2) + random((int)(parrylvl/2)) )
	{
		weapon->move(obj);
		message_vision(HIY"$N嘴角露出一丝冷笑，一抬手便将青蜂钉收笼在衣袖里。\n"NOR, obj);
		return 1;
	}
	if( attacklvl < dodgelvl )
	{
		message_vision(HIY"$N潇洒地一转身，避开了青蜂钉。\n"NOR, obj);
		return 1;
	}
	if( attacklvl < parrylvl )
	{
		weapon->move(obj);
		message_vision("$N躲闪不及，一张嘴，居然咬住了青蜂钉！\n"NOR, obj);
		return 1;
	}

/* 命中 */

	if( attacklvl > parrylvl + dodgelvl + random((parrylvl + dodgelvl) * 2))
	{
		message_vision(HIR"$N一楞神，一声闷哼，喉头赫然钉着一支青蜂钉！\n"NOR, obj);
		obj->die();
	}
	else
	if( attacklvl > parrylvl + dodgelvl + random(parrylvl + dodgelvl) )
	{
		message_vision(HIR"$N一个躲闪不及，一声惨呼，青蜂钉正钉在$N的脑门！\n"NOR, obj);
		obj->unconcious();
	}
	else
	if( attacklvl > random(parrylvl + dodgelvl) )
	{
		message_vision(RED"$N一个躲闪不及，一声惨呼，青蜂钉正钉在$N的胸口！\n"NOR, obj);
		if(damage < 11) obj->unconcious();
		else obj->receive_wound("qi", damage-10);
		obj->start_busy(3);
	}
	else
	if( attacklvl > parrylvl )
	{
		message_vision(HIM"$N一个鹞子翻身，结果青蜂钉呼地一声，正钉在$N的大腿上！\n"NOR, obj);
		obj->receive_wound("qi", (int)(damage/2));
		obj->start_busy(3);
	}
	else
	if( attacklvl > dodgelvl )
	{
		message_vision(MAG"$N躲闪不及，青蜂钉呼地一声钉在$N的胳膊上！\n"NOR, obj);
		obj->receive_wound("qi", (int)(damage/3));
		obj->start_busy(3);
	}
	else
	{
		message_vision(HIW"$N纵身一跃，但青蜂钉在$N的手臂上划出了一道伤口！\n"NOR, obj);
		obj->receive_wound("qi", (int)(damage/10));
		obj->start_busy(1);
	}
	return 1;
}

