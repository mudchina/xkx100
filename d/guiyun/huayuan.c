// Room: /guiyun/huayuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这是一处典型的江南园林，规模虽不大，构造得却颇为精致，想必
当年建园之人很费了一番心力。园中花气袭人，莺啼燕舞，柳条随风，
绿波荡漾，只待得片刻便令人如沐春风，流连忘返。
LONG );
	set("outdoors", "guiyun");
	set("exits", ([
		"east" : __DIR__"zoulang9",
	]));
	set("objects", ([
		__DIR__"npc/xiaoju" : 1,
	]));
	setup();
	replace_program(ROOM);
}
