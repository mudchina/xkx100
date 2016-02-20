// Room: /d/wuyi/yunwo.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "云窝");
	set("long", @LONG
云窝位于第五曲北。周围苍崖耸立，碧水回流，修竹丛生，怪石横
陈。云窝前有一黝黑如巨象的“铁象石”，石前为下云窝，石后为上云
窝。大小洞穴十余处。每当冬春时节，一早一晚，从洞里冒出缕缕淡淡
云雾，在峰石之间来回飘荡，舒卷自如，变幻莫测，自古此处边式道士
方家潜度所在。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"fuhuyan",
		"north"  : __DIR__"jiesunfeng",
		"south"  : __DIR__"5qu",
		"eastup" : __DIR__"yinpingfeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

