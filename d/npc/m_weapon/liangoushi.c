// ROOM lianbianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "银钩洞");
	set("long", @LONG
这里是玄兵古洞的打造钢钩的地方。南疆荒僻，山林隐密，穿过绞
缠交错的灌木丛，是一眼大石垒成的窑洞，石头砌了口大灶，火烧得正
旺，洞口潮湿阴暗，水气弥漫，洞里却干爽明亮，热气灼人。一个小伙
儿懒洋洋地靠在洞壁，两手交叉放在胸前，嘴里叼了根狗尾巴草，似笑
非笑地看着你。
LONG  );
	set("exits", ([
		"east" : "/d/wudujiao/wdsl3",
	]));
	set("objects",([
		__DIR__"npc/shigou" :1,
	]));
	set("coor/x", -44980);
	set("coor/y", -81060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
