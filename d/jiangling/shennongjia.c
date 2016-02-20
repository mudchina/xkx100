//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "神农架");
	set ("long", @LONG
这是一片绵延不绝的山岭，方圆几千里。相传上古时神农氏曾在这
里遍尝百草，因千峰陡峭，须搭架采药，故得“神农架”地名。这里冷
杉、箭竹、香柏林立，古树参天密布，药草遍地，野果满缀，异兽时现。
层峦叠嶂中，可见山峰云雾缭绕，似有积雪覆盖。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
                "east" : __DIR__"longzhong",
                "south": __DIR__"shandao6",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
