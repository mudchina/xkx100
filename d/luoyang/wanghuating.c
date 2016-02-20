//  Room:  /d/luoyang/wanghuating.c

inherit  ROOM;

void  create  ()
{
	set("short",  "花厅");
	set("long",  @LONG
你走进王家花厅，才领会到在洛阳，怎样才叫姹紫嫣红，什么样才
叫春色无边。花厅中，小小花径纵横蜿蜒，草色连壁。花厅中央是个石
亭，那里就是王家闲来讲经论武之所。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"wangdatang",
		"north"  :  __DIR__"wanglianwu",
		"west"   :  __DIR__"wangxiangfang",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wangzhongqiang" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -600);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}