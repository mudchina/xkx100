// Room: /heizhao/xiaowu.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
你快步走近瀑布，只见柳树下那人头戴斗笠，身披蓑衣，坐在
一块石上，正自垂钓。这瀑布水势湍急异常，一泻如注，水中哪里
有鱼？纵然有鱼，又哪有余暇吞饵？看那人时，见他双目一动不动
的凝视水中。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"pubu",
		"north" : __DIR__"pububian",
	]));
	set("coor/x", -5020);
	set("coor/y", -1270);
	set("coor/z", 20);
	setup();
}

void init()
{
	object ob = this_player();
	if (!ob->query_temp("yu_allow"))
	{
message_vision("\n点苍渔隐看到$N闯进屋去，钓竿一伸，把$N拖了出来！\n\n", ob);
		message("vision","只听“呀”地一声，" + ob->query("name") +
		"从小屋里飞了出来，摔在地上。\n", environment(ob), ob);
		ob->move(__DIR__"pubu");
		return;
	}
}