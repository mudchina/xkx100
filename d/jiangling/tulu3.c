//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土路，通往深山的小山村。两边是没膝的长草，路边林
木渐行渐密。山里风光，就是清清流水畔的袅袅白烟，西边看去，好象
就要到了。一对黄黑相间的大蝴蝶飞在草丛中，一会儿飞到东，一会儿
飞到西，但两只蝴蝶始终不分开。湘西一带的人管这种彩色大蝴蝶叫“
梁山伯，祝英台”。这种蝴蝶定是雌雄一对，双宿双飞。
LONG );
	set("exits", ([
		"east"     : __DIR__"tulu2",
		"westup"   : __DIR__"tiandi",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1600);
	set("coor/y", -2200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}