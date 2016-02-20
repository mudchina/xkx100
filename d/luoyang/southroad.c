//  Room:  /d/luoyang/southroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "洛川街");
	set("long",  @LONG
湿润的青石路显然是刚刚下过雨，因为来往行人过多，路面多少有
些坑坑凹凹，一不留神很容易被绊到。这条街便是因为南面的洛水而得
名。
　　南面是洛阳城的南门，北面是洛阳城中心鼓楼，而西面则是一家专
门卖唐三彩的店铺，东面是一家卖牡丹花的店铺。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"huadian",
		"west"      :  __DIR__"dianpu",
		"south"     :  __DIR__"southgate",
		"north"     :  __DIR__"center",
		"southwest" :  __DIR__"luoshenmiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/village/npc/girl" : 1,
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
