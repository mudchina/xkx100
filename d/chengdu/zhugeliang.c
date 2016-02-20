// Room: zhugeliang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "诸葛亮殿");
	set("long", @LONG
这里是武侯祠的正殿诸葛亮殿。武侯羽扇纶巾一如生前。两边诸葛瞻
和诸葛尚父子塑像也栩栩如生。挂在殿门两壁的，由诗圣杜甫笔下流露的
千古名联：“三顾频频天下事，两朝开济老臣心。”道尽了这个千古风范
的一生心事。
LONG );
	set("exits", ([
		"southdown" : __DIR__"liubeidian",
	]));
	set("objects", ([
		__DIR__"npc/youke" : random(3),
	]));
	set("coor/x", -8070);
	set("coor/y", -3000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
