// Room: /d/yanziwu/huafang.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "五湖舫");
	set("long", @LONG
堤岸边紧靠着一艘三丈长许的汉白玉画舫。前桅上高挂着一盏红灯
笼。舫中雕栏琉瓦，透着江南水乡的灵气。每个窗洞中桌台上摆放着红
烛，想来静夜红烛，定有十分情调。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"westup" : __DIR__"hongxia1",
	]));
	set("coor/x", 1260);
	set("coor/y", -1250);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}