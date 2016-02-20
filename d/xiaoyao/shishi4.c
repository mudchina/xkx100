// shishi4.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "地下石室");
	set("long", @LONG
这是一个地下的秘密石室，四面可以感觉得到的只有强烈的杀气，
以及处身地底的一些难闻的气味。在微弱的灯光下，你竟然看到有个人
站着那里。继续往下好象还有路。
LONG );
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	set("objects",([
//		__DIR__"npc/qingyun" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21030);
	set("coor/z", -50);
	setup();
}

/*int valid_leave(object me,string dir)
{
        if(dir=="down" && (!me->query("family") || (me->query("family/master_id")!="xiaoyao zi")) && present("qingyun",environment(me))) 
             return notify_fail("青云一个闪身，挡住了你的去路！\n");
        return ::valid_leave(me,dir);
}*/