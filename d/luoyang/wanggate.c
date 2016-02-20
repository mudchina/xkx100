//  Room:  /d/luoyang/wanggate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大门");
	set("long",  @LONG
这里是大名鼎鼎的洛阳金刀王家。但见房舍十分高大，朱红漆的大
门，门上两个大铜环，擦得晶光雪亮，门楣上有朱漆涂就的“金刀”二
字，八名壮汉垂手在大门外侍候。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"enter"  :  __DIR__"wangdayuan",
		"south"  :  __DIR__"westroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/zhuanghan" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -600);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if ( objectp(present("zhuang han", environment(me))) && dir == "enter")
           return notify_fail("壮汉拦住你说：你来洛阳金刀门撒野？快出去！\n");
        return ::valid_leave(me, dir);
}
