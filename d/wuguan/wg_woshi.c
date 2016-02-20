// wg_woshi.c

inherit ROOM;

void create()
{
	set("short","卧室");
	set("long", @LONG
这里是武馆馆主的卧室，房子并不大，很整洁简朴，被子叠的整整
齐齐，帐子挂了起来，靠窗边摆了一盆盆景，一张小桌，放着几本书。
LONG);
	set("exits", ([
		"west" : __DIR__"wg_lang5",
	]));
	set("objects", ([
		__DIR__"npc/wg_furen" : 1,
	]));
	set("coor/x", 41);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
