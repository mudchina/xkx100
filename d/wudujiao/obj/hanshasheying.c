// hanshasheying.c 含沙射影

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name("含沙射影", ({ "han sha she ying", "hssy" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是五毒教的奇门暗器「含沙射影」，样子象一条腰带，可以束在腰间。\n带中间有一个扁扁的小铁盒，只要在腰间一按(shot)就可以发射出细如牛毛的毒针。\n") ;
		set("unit", "个");
		set("value", 0);
		set("zhen", 10);
		set("material", "iron");
		set("armor_prop/armor", 3);
	}
	setup();
}

void init()
{
	add_action("do_shot","shot");
}

int do_shot(string arg)
{
	object me,ob,target;
	int myskill , tgskill;
	int mylev ,damage;
	string fam;

	me = this_player();

	if( me->query_temp("armor/waist") != this_object() )
		return notify_fail("你对着你的腰间一摸，糟糕！你还没把含沙射影装上呢！\n");

	if( !arg ) return notify_fail("你想对谁发射含沙射影？\n");

	if( !objectp(target = present(arg, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if( target->query("id")==me->query("id"))
		return notify_fail("你想杀自己吗？\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("含沙射影只能对战斗中的对手使用。\n");

	if ( environment(me)->query("no_fight"))
		return notify_fail ("这里不准战斗！\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(me->is_busy() )
		return notify_fail("你正忙着哪。\n");

	if( this_object()->query("zhen") < 1 )
	{
		remove_call_out("destroy_box");
		call_out ("destroy_box" , 0 ) ;
		return notify_fail("铁盒中的毒针已经射光了。\n");
	}

	if( !objectp(ob = present("han sha she ying", me)) )
		return notify_fail("你没有这种东西。\n");

	myskill = me->query_skill("five-poison",1) + me->query_skill("dodge",1);
	tgskill = target->query_skill("dodge",1);
	mylev = me->query_skill("five-poison");

	if( (string)this_player()->query("family/family_name")!="五毒教" )
	{
		message_vision("\n$N左手在腰间一阵乱按！\n", me);
		return 1;
	}
	if( ob->query("own_name")!= me->query("id") )
	{
		message_vision("\n$N左手在腰间一阵乱按！\n", me);
		remove_call_out("destroy_box");
		call_out ("destroy_box" , 0 ) ;
		return 1;
	}

	if ( mylev <= 50 )
		return notify_fail("你的毒技还不熟练，无法使用含沙射影！\n");

	this_object()->add("zhen", -1);
	message_vision(HIR"\n$N一声轻笑，左手不经意的在腰间一按。只听得一阵嗤嗤的破空声。\n"NOR,me,target);
	me->start_busy(2+random(2)) ;
	if( !target->is_killing(me) ) target->kill_ob(me);
	if(  random(myskill) < tgskill )
		message_vision("\n$n大叫一声，猛的一个旱地拔葱身行冲起数丈来高，堪堪躲过了$N的毒针！\n",me,target);
	else {
		message_vision("\n$n躲闪不及，被无数细如牛毛的毒针打了一身，不由的发出一声惨嚎！\n",me,target);
		tell_object (target, HIR "\n你只觉得脸上、胸前一痛，而后是奇痒难熬，一定是中毒了。\n"NOR);
		damage=(int)me->query_skill("five-poison",1)*4 - (target->query("max_neili")/5);
		if( damage < 100 ) damage = 100;
		if( damage > 800 ) damage = 800;
		target->receive_wound ("qi",damage) ;
		target->apply_condition("snake_poison", (int)target->query_condition("snake_poison") + damage/5 );
		target->apply_condition("wugong_poison", (int)target->query_condition("wugong_poison") + damage/5 );
		target->apply_condition("zhizhu_poison", (int)target->query_condition("zhizhu_poison") + damage/5 );
		target->apply_condition("xiezi_poison", (int)target->query_condition("xiezi_poison") + damage/5 );
		target->apply_condition("chanchu_poison", (int)target->query_condition("chanchu_poison")+damage/5 );
		target->start_busy (4);
		}
	return 1;
}

void destroy_box()
{
	message_vision("忽然" + (string)this_object()->query("name") + "掉在地上，摔成了一堆铁片。\n", environment(this_object()));
	destruct(this_object());
}
