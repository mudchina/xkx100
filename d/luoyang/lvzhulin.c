//  Room:  /d/luoyang/lvzhulin.c

inherit  ROOM;

void  create  ()
{
	set("short",  "绿竹林");
	set("long",  @LONG
一片绿茸般的竹林把燥热挡在视野之外，这里是一片清凉世界。小
石子路在竹林中穿梭而过，石子间是细密的青苔，透着一股凉爽，自脚
跟沁入胸臆。北面是个小院子。琴声益发悦耳了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"xiaoxiang",
		"north"  :  __DIR__"lvzhuxiaoyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}