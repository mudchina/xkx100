//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "虫二茶馆");
	set("long", @LONG
一走进来，就闻到一股茶香沁入心脾，你不禁精神为之一爽。几张
八仙桌一字排开，坐满了客人，或高声谈笑，或交头接耳。你要打听江
湖掌故和谣言，这里是个好所在。这家茶馆的主人是个风雅之士，起名
“虫二”要的是“风月无边”。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"dongjie2",
	]));
	set("objects", ([
		__DIR__"npc/chongyi" : 1,
	]));
	set("coor/x", -1460);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}