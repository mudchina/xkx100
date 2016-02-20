// Room: /binghuo/lingshegang.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "灵蛇岛海港");
	set("long", @LONG
这是个树木葱翠的大岛，岛上奇峰挺拔，耸立着好几座高山。岛
东端山石直降入海，并无浅滩，往来船只近岸泊就。此时岸边正好有
一艘大船(chuan)，可是奇怪的是主桅上居然没有帆布。
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("item_desc", ([
		"chuan" : "一艘三桅白帆海船。上船就可以出海。\n",
	]));
	set("exits", ([
		"westup"  : __DIR__"lingsheroad4",
		"enter"   : __DIR__"northboat1",
	]));
	setup();
	replace_program(ROOM);
}

