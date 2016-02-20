// Room: /beijing/mianguan.c


inherit ROOM;

void create()
{
	set("short", "面馆");
	set("long", @LONG
这是一家价钱低廉的面馆，生意非常兴隆。外地游客多选择这里落
脚，你可以在这里打听到各地的风土人情。穷人们也都喜欢来这里。店
小二里里外外忙得团团转，接待着南腔北调的客人。几张脏乎乎的小木
桌旁，坐满了各种各样的食客。
LONG );
        set("no_sleep_room",1);
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
                "/d/huashan/npc/haoke" :2,
	]));
	set("exits", ([
		"west" : __DIR__"alley1",
	]));
	set("coor/x", -210);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir == "west")&& present("mian", this_player())
	&& objectp(present("xiao er", environment(me)))&&living(present("xiao", environment(me))))
	 return notify_fail("小二陪笑道：对不起，面不能带出面馆。\n");
return ::valid_leave(me,dir);
}
