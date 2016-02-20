// dating.c 大厅

inherit ROOM;

void create()
{
	set("short","大厅");
	set("long",@LONG
这里是寺内的大厅，几位有道的高僧在高声辩论。看来正在引经据
典，争斗机锋。
LONG );
	set("exits",([
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang2",
		"northeast" : __DIR__"chanshi",
		"southeast" : __DIR__"cangjing",
		"northwest" : __DIR__"cangjingge",
	]));
	set("objects", ([
		CLASS_D("xueshan")+"/fawang" :1,
	]));
	set("coor/x", -70000);
	set("coor/y", -19890);
	set("coor/z", 130);
	setup();
}