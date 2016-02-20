//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "菜田");
	set("long", @LONG
这是一块菜地，但见一片青绿，都种满了空心菜。白色的蛾蝶在菜
丛中上下飞舞。“空心菜”是湘西一带最寻常的蔬菜，粗生粗长，菜茎
的心是空的。给人取了这个绰号，就是笑人直肚直肠，没半点心事的意
思。
LONG );
	set("exits", ([
		"west"     : __DIR__"maxipu",
	]));
	set("objects", ([
		__DIR__"npc/diyun" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1600);
	set("coor/y", -2210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}