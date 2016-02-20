// Room: /d/yanziwu/huapu1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "花圃");
	set("long", @LONG
这里是蔓陀山庄中的花圃。花圃中摆了很多花盆和新泥，背荫处花
盆里多是新苗。四处散落着不少不知名的花儿，有繁有凋大凡茶花，皆
枝条窈窕，弱不胜风。
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north"  : __DIR__"path5",
		"east"   : __DIR__"huapu2",
	]));
	set("objects", ([
		__DIR__"obj/chutou" : 1,
		"/d/dali/obj/chahua9" : 1,
	]));
	set("coor/x", 1240);
	set("coor/y", -1280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}