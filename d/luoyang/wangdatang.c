//  Room:  /d/luoyang/wangdatang.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大堂");
	set("long",  @LONG
一进大堂门，只见梁上悬着一块黑漆大匾，写着“见义勇为”四个
金字，下面落款是河南省的巡抚某人。看来王家的势力非只武功上的名
声而来的。这里也是王家迎宾欢宴的地方，檐下栏边，均装饰的十分华
贵。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"wanghuating",
		"south"  :  __DIR__"wangdayuan",
		"west"   :  __DIR__"wangzhangfang",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", -600);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}