// Room: /city/chaguan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "富春茶社");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。茶楼西边
面河围以朱栏，摆有数张茶几，上置盆景花木，数名儒生模样的客人在
或高声谈笑，或交头接耳或，品茶闲谈。你要想打听江湖掌故和谣言，
这里是个好所在。南墙挂着几幅字画，中悬巨幅扇面。中间摆着两张海
梅方桌，各配四张白瓷凳。此处闲静淡雅，当是休栖之佳处。近来茶楼
隔了几个单间供茶客们闲聊用，边上挂着一块牌子。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"qionghuajie",
		"west"  : __DIR__"shilijie1",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/player_b"->foo();
}