// Room: /d/5lt/chaguan.c

inherit ROOM;

void create()
{
	set("short", "陶然茶居");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。茶楼东面
摆有数张茶几，上置盆景花木，数名儒生模样的客人在或高声谈笑，或
交头接耳，或品茶闲谈。你想打听江湖掌故和谣言，这里是个好所在。
南墙挂着几幅字画，中悬巨幅扇面。中间摆着两张海梅方桌，各配四张
白瓷凳。此处闲静淡雅，当是休栖之佳处。
LONG);
	set("resource/water", 1);
	set("exits", ([
		"west"  : __DIR__"sroad1",
	]));
	set("objects", ([
	]));
	set("coor/x", -140);
	set("coor/y", -15);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}