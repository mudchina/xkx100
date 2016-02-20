// huoqian.c
//modefied by sega 1/15/99 改成不能在no_fight的地方catch

#include <ansi.h>
inherit ITEM;
//inherit F_CLEAN_UP;
void setup()
{}

void init()
{
	add_action("do_watch","guancha");
	add_action("do_watch","watch");
	add_action("do_catch","daibu");
	add_action("do_catch","catch");
	add_action("do_catch","kill");
	add_action("do_catch","hit");
}
int is_container() { return 1; }

void create()
{
	set_name(HIR"火签"NOR, ({"huo qian","hq" }));
	set_max_encumbrance(10);
	set("unit", "块");
	set("long", "这是一块朱红的火签，精钢打造，用来证明官府人士的身份。\n带着它你就有权搜寻罪犯(guancha/watch)，逮捕嫌疑犯(daibu/catch)。\n");
	set("value", 0);
	set("no_drop", "这样东西不能离开你。\n");
	set("no_get", "这是官府的东西，平常人拿了会惹麻烦的。\n");
	set("no_get_from", "这是官府的东西，平常人拿了会惹麻烦的。\n");
	set("no_put", "这是官府的东西，别到处乱放。\n");
	set_weight(200);
	set("place","on");

	setup();
}
int do_watch(string arg)
{
	object obj,new_obj;
	object me = this_player();
	object ob = this_object();
	string targ;

	if (!me->query("officerlvl"))
		return notify_fail("你并非朝廷官员，何必操这份闲心？\n");

	if (!ob=present("huo qian",me))
		return notify_fail("什么？\n");
	if (me->query_temp("bt/finish"))
		return notify_fail("程大人等着回话哪，你还在磨蹭什么？\n");
	if (!arg||!obj=present(arg,environment(me)))
		return notify_fail("你要观察谁？\n");
	if (!obj->is_character() || obj->is_corpse() )
		return notify_fail("你只能观察一个活的物体。\n");
	if (!present("picture",ob))
		return notify_fail("你早已经发现了嫌疑犯，还磨蹭什么？\n");
	if (me->is_busy() )
		return notify_fail("你正忙着。\n");

	targ=obj->query("name");
	tell_object(me,"你用锐利的眼神盯着"+targ+"。\n\n");
	me->start_busy(1);
	if (obj->query("bt_tufei")==me->query_temp("bt/npc") &&
		random(me->query("kar")+15)>20 &&
		!environment(me)->query("no_fight") )
	{
		switch(random(5))
		{
			case 0:
tell_object(me,WHT"你发现"+targ+"忽然把头一低，似乎想避开你的目光。\n\n"NOR);
				break;
			case 1:
tell_object(me,WHT"你发现"+targ+"忽然打了个哆嗦，面如土色。\n\n"NOR);
				break;
			case 2:
tell_object(me,WHT"你发现"+targ+"太阳穴高高坟起，似乎是个练武的人。\n\n"NOR);
				break;
			case 3:
tell_object(me,WHT"你发现"+targ+"腰间鼓鼓囊囊的，样子象是一件兵刃。\n\n"NOR);
				break;
			case 4:
tell_object(me,WHT"你发现"+targ+"的眼中精光一闪，马上又变的一脸茫然。\n\n"NOR);
				break;
		}
		me->set_temp("bt/faxian",1);
		obj->set_temp("bt_faxianed",me->query("id"));
	}
	else
	{
		switch(random(11))
		{
			case 0:
tell_object(me,"只见"+targ+"正挤眉弄眼，色迷迷的东张西望。\n\n");
				break;
			case 1:
tell_object(me,"只见"+targ+"饿得面黄肌瘦，骨瘦如柴。\n\n");
				break;
			case 2:
tell_object(me,"只见"+targ+"面颊微红，一脸娇羞的模样。\n\n");
				break;
			case 3:
tell_object(me,"只见"+targ+"满脸横肉，嘴脸凶顽。\n\n");
				break;
			case 4:
tell_object(me,"只见"+targ+"悲痛欲绝，哭的象个泪人似的。\n\n");
				break;
			case 5:
tell_object(me,"只见"+targ+"手足僵硬，浑身散发着金属光泽。\n\n");
				break;
			case 6:
tell_object(me,"只见"+targ+"面无表情，呆若木鸡。\n\n");
				break;
			case 7:
tell_object(me,"只见"+targ+"长得尖嘴猴腮，目光狡诈。\n\n");
				break;
			case 8:
tell_object(me,"只见"+targ+"干笑几声，脸上挤出一丝媚笑。\n\n");
				break;
			case 9:
tell_object(me,"只见"+targ+"挺胸叠肚，一脸傲慢的神色。\n\n");
				break;
			case 10:
tell_object(me,"只见"+targ+"长得明眸皓齿，一脸天真的神色。\n\n");
				break;
		}
	}
	return 1;
}
int do_catch(string arg)
{
	object obj,new_obj;
	object me = this_player();
	object ob = this_object();			//100
	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if (!ob=present("huo qian",me))
		return notify_fail("什么？\n");
	if (!me->query("officerlvl"))
		return notify_fail("你并非朝廷官员，何必操这份闲心？\n");
	if (me->query_temp("bt/finish"))
		return notify_fail("程大人等着回话哪，你还在磨蹭什么？\n");
	if (!arg||!obj=present(arg,environment(me)))
		return notify_fail("你要逮捕谁？\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("你只能逮捕一个活人。\n");
	if( !me->query_temp("bt/faxian")
		|| obj->query_temp("bt_faxianed")!=me->query("id") )
		return notify_fail("扬州纪律严明，没有证据怎好拿人？\n");
	message_vision ("$N对着$n冷笑一声道：阁下的案子发了，老老实实跟本官
走一趟。\n\n",me,obj);
	message_vision (RED"$n大叫一声揭开伪装，露出本来面目。\n$n大喝道：老子和你拼了！\n\n"NOR,me,obj);
	obj->delete_temp("bt_faxianed");
	destruct(obj);
	new_obj = present("picture",ob);
	new_obj->move(environment(me));
	new_obj->kill_ob(me);
	me->kill_ob(new_obj);
	new_obj->set_leader(me);
	new_obj->set_temp("bt_npc",me->query_temp("bt/npc"));
	new_obj->set_temp("bt_ownname",me->query("id"));
	new_obj->delete("no_see");
	new_obj->start_busy(1);
	me->delete_temp("bt/faxian");
	return 1;
}

