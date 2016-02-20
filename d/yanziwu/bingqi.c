//ROOM: /d/yanziwu/bingqi.c

inherit ROOM;

void create()
{
	set("short", "神兵阁");
	set("long",@LONG
这里就是慕容家藏兵之所。这里摆设着慕容家历代祖先纵横江湖所
用的兵器，以及他们百战获得的神兵。所有的这些摆设已显得相当古旧
了。在阁楼角，落堆放着一摞摞的寻常兵器。
LONG );
	set("exits", ([
		"north": __DIR__"chixia",
	]));
	set("objects", ([
		"/clone/weapon/changjian": random(2),
		"/clone/weapon/changbian": random(2),
		"/clone/weapon/changqiang": random(2),
		"/clone/weapon/gangdao": random(2),
		"/clone/weapon/dagger": random(2),
		"/clone/weapon/gangzhang": random(2),
		"/clone/weapon/jili": random(2),
		"/clone/weapon/hammer": random(2),
		"/clone/weapon/lianzi": random(2),
		"/clone/weapon/qimeigun": random(2),
	]));
	set("coor/x", 820);
	set("coor/y", -1860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}