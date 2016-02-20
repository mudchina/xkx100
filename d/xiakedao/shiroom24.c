// /d/xiakedao/shishi24.c 侠客岛 石室24

inherit ROOM;
#include <ansi.h>

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
这里火光昏暗，只见那龙岛主与木岛主盘膝坐在锦垫之上，面对
石壁(wall)，凝神苦思。此石室已是山腹最深处，却宽阔高大，足可
容下近百人。洞中火把亦是其他洞的二三倍之多。
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「白首太玄经」几个大字。字的下方刻的是密密麻麻
的蝌蚪文，成千上万。文字排列甚不整齐，或横或竖，或直或斜。左
下的大片甚至混成一团难分次序，委实难以辨认。
WALL
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
	set("coor/x", -3100);
	set("coor/y", -25600);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_study","think");
        add_action("do_canwu","canwu");
}
int do_canwu(string arg)
{
	string swith,where;
	object me = this_player();

	if (sscanf(arg,"%s from %s",swith,where)!=2)
  	return notify_fail("指令格式：yanjiu 特殊技能 from wall\n");

  if (where != "wall") 
    return notify_fail("这里没有这个东西给你研究。\n");

  if (me->is_busy())
    return notify_fail("你现在正忙着呢。\n");

  if (me->is_fighting())
    return notify_fail("你在战斗哦？！小心，来了！！！\n");

  if ((int)me->query_skill("force", 1) < 300)
    return notify_fail("你的内功修为不够，无法贯通石壁上的绝学！\n");

  if ((int)me->query("max_neili") < 3000)
    return notify_fail("你的内力修为不足，无法贯通石壁上的绝学！\n");

  if ((int)me->query("jing") < 100)
    return notify_fail("你的精力无法集中，无法领悟石壁上的绝学！\n");

  if (me->query_skill("taixuan-gong", 1) < 200)
    return notify_fail("你对太玄功所知实在有限，无法领悟石壁上的绝学！\n");

    me->receive_damage("jing", 95);

    me->start_busy(2 + random(4));
  if (swith == "taixuan" || swith == "白首太玄经")
  {
  	if (me->query("can_perform/taixuan-gong/taixuan"))
  	  return notify_fail("这项绝学你不是已经会了吗？\n");
  	if (random(20)==1)
	{
		write(HIM "猛然间，你一声长啸，胸中豁然贯通，再无疑虑。\n" NOR);
		write(HIC "你终于通晓了绝学「白首太玄经」。\n" NOR);
		me->set("can_perform/taixuan-gong/taixuan",1);
		return 1;
	}
  }
  return notify_fail("你试图从石壁上研究有关「白首太玄经」的内容，但却没什么效果！\n");
}
int do_study(string arg)
{
	object me, where;
	int jing_cost, learn_pot, item, times, i, success;
	string skillname;

	me = this_player();
	if ( !me->query( "xkd/ling" ) )
		return notify_fail( "未经岛主允许，不得擅自观看石壁。\n" );
	if ( !me->query_temp( "winner" ) )
		return notify_fail( "未经岛主允许，不得擅自观看石壁。\n" );
	if( !arg ) return notify_fail("你要领悟什么？\n");
	if(  arg != "wall"  )
		return notify_fail("指令格式：think wall <次数>\n");
	if ((int)me->query("combat_exp")<50000)
		return notify_fail("你的经验太低, 没法领悟石壁内容。\n");
	jing_cost = 30 + random(me->query_int());
	if( me->query("jing") < jing_cost || me->query("eff_qi") < 100)
		return notify_fail("你现在太累了，领悟不了这么多次，休息一会儿再来吧。\n");
	me->receive_damage("jing",jing_cost);
	if((int)(me->query_skill("taixuan-gong",1) * 
		me->query_skill("taixuan-gong",1) * 
		me->query_skill("taixuan-gong",1)) /10 >= me->query("combat_exp"))
	{
		write("你对着石壁冥思苦想了一会，毫无收获。\n");
		return 1;
	}
	success = 0;
	if (me->query_skill("taixuan-gong",1)<10)
	{
		if (random(20)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<50)
	{
		if (random(10)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<100)
	{
		if (random(5)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<200)
	{
		if (random(3)==1)
		success = 1;
	}
	else 	if (me->query_skill("taixuan-gong",1)>=200)
	{
		write("你望着石壁冥思苦想了一会，发觉上面的东西对你来说太浅薄了。\n");
		return 1;
	}
	learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int")) - (int)(me->query_skill("literate",1)/2);
	if (success == 1)
	{
		message_vision(CYN"$N面对着石壁抱头苦思，突然间，如同升仙一般拔地而起，原来竟然领悟到了太玄神功的一些精髓！\n"NOR,me);
		me->improve_skill("taixuan-gong", learn_pot);
	}
	else
	{
		message_vision(HIR"$N面对着石壁抱头苦思，突然间，如同升仙一般拔地而起，不料一头撞在了石壁上！\n"NOR,me);
		me->receive_wound("jing",10);
	}
	return 1;
}
