// chengruiting.c

inherit ROOM;

void create()
{
	set("short", "澄瑞亭");
	set("long", @LONG
御花园两边建有鱼池, 池上建亭, 这里就是澄瑞亭. 亭子朝南抱厦, 
亭座下有涵洞, 洞中有井. 夏日, 池水清澈, 金鱼戏游于荷花之下. 冬
日, 池水结冰, 金鱼就入井过冬. 
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"southeast" : __DIR__"yuhuayuan",
	]) );
	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 5340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}