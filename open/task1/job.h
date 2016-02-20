// job2.h
#include <ansi.h>

mapping *quest = ({
({
	([	"name"  : "江湖宵小",
		"id"    : "jianghu  xiaoxiao",
		"where" : __DIR__"task1/xiaoxiao",]), 
	([	"name"  : "山贼", 
		"id"    : "shan  zei",
		"where" : __DIR__"task1/shanzei",]),
}), 
({
	([	"name"  : "山贼", 
		"id"    : "shan  zei",
		"where" : __DIR__"task1/shanzei",]),
	([	"name"  : "盖一鸣",
		"id"    : "gai  yiming",
		"where" : __DIR__"task1/gaiyiming",]),
	([	"name"  : "常长风",
		"id"    : "chang  changfeng",
		"where" : __DIR__"task1/chang",]),
	([	"name"  : "花剑影",
		"id"    : "hua  jianying",
		"where" : __DIR__"task1/hua",]),
	([	"name"  : "逍遥子",
		"id"    : "xiaoyao  zi",
		"where" : __DIR__"task1/xiao",]),
	([	"name"  : "黄须道人",
		"id"    : "huangxu  daoren",
		"where" : __DIR__"task1/huangxu",]),
	([	"name"  : "恶僧",
		"id"    : "e  seng",
		"where" : __DIR__"task1/eseng",]),
	([	"name"  : "曹化淳",
		"id"    : "cao  huachun",
		"where" : __DIR__"task1/cao",]),
	([	"name"  : "朱安国",
		"id"    : "zhu  anguo",
		"where" : __DIR__"task1/zhu",]),
}), 
({
	([	"name"  : "江洋大盗",
		"id"    : "jiangyang  dadao",
		"where" : __DIR__"task1/dadao",]),
	([	"name"  : "草寇",
		"id"    : "cao  kou",
		"where" : __DIR__"task1/caokou",]),
	([	"name"  : "恶霸",
		"id"    : "e  ba",
		"where" : __DIR__"task1/eba",]),
//	([	"name"  : "宋扬",
//		"id"    : "song  yang",
//		"where" : __DIR__"task1/songyang",]),
	([	"name"  : "全二风",
		"id"    : "quan  erfeng",
		"where" : __DIR__"task1/quan",]),
	([	"name"  : "孟正鹏",
		"id"    : "meng  zhengpeng",
		"where" : __DIR__"task1/meng",]),
	([	"name"  : "鲜于通",
		"id"    : "xianyu  tong",
		"where" : __DIR__"task1/xian",]),
	([	"name"  : "麦鲸",
		"id"    : "mai  jing",
		"where" : __DIR__"task1/maijing",]),
	([	"name"  : "过三拳",
		"id"    : "guo  sanquan",
		"where" : __DIR__"task1/guo",]),
}), 
({
	([	"name"  : "赵一伤",
		"id"    : "zhao  yishang",
		"where" : __DIR__"task1/zhao",]),
	([	"name"  : "钱二败",
		"id"    : "qian  erbai",
		"where" : __DIR__"task1/qian",]),    
	([	"name"  : "孙三毁",
		"id"    : "sun  sanhui",
		"where" : __DIR__"task1/sun",]),  
	([	"name"  : "李四摧",
		"id"    : "li  sicui",
		"where" : __DIR__"task1/li",]), 
	([	"name"  : "周五输",
		"id"    : "zhou  wushu",
		"where" : __DIR__"task1/zhou",]), 
	([	"name"  : "吴六破",
		"id"    : "wu  liupo",
		"where" : __DIR__"task1/wu",]), 
	([	"name"  : "郑七灭",
		"id"    : "zheng  qimie",
		"where" : __DIR__"task1/zheng",]), 
	([	"name"  : "王八衰",
		"id"    : "wang  bashuai",
		"where" : __DIR__"task1/wang",]), 
	([	"name"  : "元广波",
		"id"    : "yuan  guangbo",
		"where" : __DIR__"task1/yuan",]), 
	([	"name"  : "徐长老",
		"id"    : "xu  zhanglao",
		"where" : __DIR__"task1/xu",]), 
}), 
({
	([	"name"  : "阿大",
		"id"    : "a  da",
		"where" : __DIR__"task1/ada",]),  
	([	"name"  : "阿二",
		"id"    : "a  er",
		"where" : __DIR__"task1/aer",]), 
	([	"name"  : "阿三",
		"id"    : "a  san",
		"where" : __DIR__"task1/asan",]), 
	([	"name"  : "玉真子",
		"id"    : "yu  zhenzi",
		"where" : __DIR__"task1/yu",]),    
	([	"name"  : "段延庆",
		"id"    : "duan  yanqing",
		"where" : __DIR__"task1/duan",]),    
	([	"name"  : "叶二娘",
		"id"    : "ye  erniang",
		"where" : __DIR__"task1/ye",]),    
	([	"name"  : "南海鳄神",
		"id"    : "nanhai  eshen",
		"where" : __DIR__"task1/nan",]),    
	([	"name"  : "云中鹤",
		"id"    : "yun  zhonghe",
		"where" : __DIR__"task1/yun",]),    
	([	"name"  : "鹿杖客",
		"id"    : "lu  zhangke",
		"where" : __DIR__"task1/lu",]),    
	([	"name"  : "鹤笔翁",
		"id"    : "he  biweng",
		"where" : __DIR__"task1/he",]),    
	([	"name"  : "达尔巴",
		"id"    : "daerba  huofo",
		"where" : __DIR__"task1/daerba",]),    
	([	"name"  : "霍都",
		"id"    : "huo  du",
		"where" : __DIR__"task1/huodu",]),    
}),
});
mapping *wheres=({	 
	(["chinese":	"白驼山",
	"weizhi" :	"/d/baituo/cao2",]),  
	(["chinese":	"长城",
	"weizhi" :	"/d/changcheng/changcheng19",]),  
	(["chinese":	"扬州城",
	"weizhi" :	"/d/city/jiaowai9",]),  
	(["chinese":	"北京城",
	"weizhi" :	"/d/city2/huayuan",]),  
	(["chinese":	"成都城",
	"weizhi" :	"/d/city3/wuhouci",]),  
	(["chinese":	"长安城",
	"weizhi" :	"/d/city4/gulou",]),  
	(["chinese":	"大理城",
	"weizhi" :	"/d/dali/tingyuan",]),  
	(["chinese":	"峨嵋山",
	"weizhi" :	"/d/emei/jieyindian",]),  
	(["chinese":	"佛山镇",
	"weizhi" :	"/d/foshan/street3",]),  
	(["chinese":	"福州城",
	"weizhi" :	"/d/fuzhou/gushan",]),  
	(["chinese":	"关外",
	"weizhi" :	"/d/guanwai/milin3",]),  
	(["chinese":	"杭州城",
	"weizhi" :	"/d/hangzhou/shiwudong",]),  
	(["chinese":	"黑木崖",
	"weizhi" :	"/d/heimuya/shijie1",]),  
	(["chinese":	"恒山",
	"weizhi" :	"/d/hengshan/yuyang",]),  
	(["chinese":	"衡山",
	"weizhi" :	"/d/henshan/nantaisi",]),  
	(["chinese":	"黄河",
	"weizhi" :	"/d/huanghe/weifen",]),  
	(["chinese":	"华山",
	"weizhi" :	"/d/huashan/yuntai",]),  
	(["chinese":	"江陵城",
	"weizhi" :	"/d/jiangling/longzhong",]),  
	(["chinese":	"嘉兴城",
	"weizhi" :	"/d/jiaxing/njroad5",]),  
	(["chinese":	"昆仑山",
	"weizhi" :	"/d/kunlun/jiuqulang2",]),  
	(["chinese":	"兰州城",
	"weizhi" :	"/d/lanzhou/street2",]),  
	(["chinese":	"灵鹫峰",
	"weizhi" :	"/d/lingjiu/jian",]),  
	(["chinese":	"灵州城",
	"weizhi" :	"/d/lingzhou/kongdi",]),  
	(["chinese":	"洛阳城",
	"weizhi" :	"/d/luoyang/wanghuating",]),  
	(["chinese":	"光明顶",
	"weizhi" :	"/d/mingjiao/tohtq3",]),  
	(["chinese":	"祁连山",
	"weizhi" :	"/d/qilian/zhutishan",]),  
	(["chinese":	"青城山",
	"weizhi" :	"/d/qingcheng/huyingting",]),  
	(["chinese":	"嵩山",
	"weizhi" :	"/d/songshan/junjigate",]),  
	(["chinese":	"苏州城",
	"weizhi" :	"/d/suzhou/liuyuan",]),  
	(["chinese":	"泰山",
	"weizhi" :	"/d/taishan/tianjie",]),  	 
	(["chinese":	"天龙寺",
	"weizhi" :	"/d/tianlongsi/tading",]),  
	(["chinese":	"铁掌峰",
	"weizhi" :	"/d/tiezhang/guangchang",]),  
	(["chinese":	"华山村",
	"weizhi" :	"/d/village/eexit",]),  
	(["chinese":	"万劫谷",
	"weizhi" :	"/d/wanjiegu/port2",]),  
	(["chinese":	"五毒教",
	"weizhi" :	"/d/wudujiao/wdsl3",]),  
	(["chinese":	"无量山",
	"weizhi" :	"/d/wuliang/road4",]),  
	(["chinese":	"无锡城",
	"weizhi" :	"/d/wuxi/road15",]),  
	(["chinese":	"襄阳城",
	"weizhi" :	"/d/xiangyang/walls3",]),  
	(["chinese":	"星宿海",
	"weizhi" :	"/d/xingxiu/shidao",]),  
	(["chinese":	"雪域",
	"weizhi" :	"/d/xuedao/shandong2",]),  
	(["chinese":	"雪山大轮寺",
	"weizhi" :	"/d/xueshan/zoulang3",]),  
	(["chinese":	"燕子坞",
	"weizhi" :	"/d/yanziwu/qiushuan",]),
	(["chinese":    "泉州",
	"weizhi" :      "/d/quanzhou/jiangjunfu1",]),
	(["chinese":    "漠北",
	"weizhi" :      "/d/mobei/hill",]),
	(["cdizhi":      "凌霄城",
	"weizhi2" :      "/d/lingxiao/laolang",]),
	(["cdizhi":      "回疆",
	"weizhi2" :      "/d/huijiang/xingtang",]),		
});
void init()
{
	add_action("do_jie", ({"xian","jie"}));
}

int do_jie(string arg)
{
	object me, ob;
	mapping weizhis, target;
//	string  weishis;
	int exp, position;

	if(!arg) return 0;
	me = this_player();
	ob = this_player(); 
	exp=(int)me->query("combat_exp"); 
	weizhis = wheres[random(sizeof(wheres))];
//	weishis = quest[random(sizeof(wheres))];

	if(arg != "wenshu" && arg != "wen") return 0;

	if(me->query_condition("dali_xuncheng") ||
		me->query_condition("gb_busy") ||
		me->query_condition("xx_task") ||
		me->query_condition("gb_songxin"))
		return notify_fail("你现在正忙着做其他任务呢！\n");
	if(me->query_condition("guanfu_task"))
		return notify_fail("你已经揭过榜了，难道不想做了？！\n");
	if(me->query_temp("guanfu_task") || present("wenshu", me))
		return notify_fail("你身上还有文书，可以通过(kan wenshu)来查询。\n");
	
	if(me->query_condition("guanfu_busy"))
		return notify_fail("你发现文书已经被人揭光了，看样子要等一会了！\n");

	if(exp<50000)
		return notify_fail("你刚想伸手，忽然看到上面凶神恶煞的画像，想了想觉得自己的这点功夫，还是算了吧。\n"); 
	if(exp>=3500000) position=5;
	else if(exp>=2000000) position=4;
	else if(exp>=1000000) position=3;
	else if(exp>=250000) position=2;
	else position=1;
//	target = quest[random(sizeof(quest))];
	target = quest[position-1][random(sizeof(quest[position-1]))]; 
	while (sizeof(filter_array(children(target["where"]),(: clonep :))) > 0)
	target = quest[position-1][random(sizeof(quest[position-1]))];
	
	if(exp>=380000)
	{
		tell_room(this_object(), HIY + me->name()
		+ "推开围观的行人，走到近前，微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR, ({ me }));
		write(HIY"你推开围观的行人，走到近前，微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR);
	}
	if(exp<=120000)
	{
		tell_room(this_object(), HIY + me->name()
		+"壮了壮胆，费力拔开行人，来到近前深深吸了口气，竭力镇定一下紧张的心情，四下看了看，悄悄把文书揭了下来。\n"NOR, ({ me }));
		write(HIY"你壮了壮胆，费力拔开行人，来到近前深深吸了口气，竭力镇定一下紧张的心情，四下看了看，悄悄把文书揭了下来。\n"NOR);
	}
	if(exp>120000 && exp<380000)
	{
		tell_room(this_object(), HIY + me->name()
		+"分开行人来到近前，目光淡淡的扫视了几眼告示，嘴角微微一翘，神态自如的把文书揭了下来。\n"NOR, ({ me }));
		write(HIY"你分开行人来到近前，目光淡淡的扫视了几眼告示，嘴角微微一翘，神态自如的把文书揭了下来。\n"NOR);
	}
	me->set_temp("mark/gkill1",1);
	me->set_temp("guanfu_target", target["id"]);
	me->set_temp("guanfu_targetnm", target["name"]);
	me->set_temp("path_rooms", target["where"]);
	me->set_temp("gstart_rooms", weizhis["weizhi"]);
	me->set_temp("ch_weizhi", weizhis["chinese"]);
	new(__DIR__"task1/wenshu")->move(me);
//	me->move(me->query_temp("start_rooms"));
	ob = new(me->query_temp("path_rooms"));
//	ob->move(__DIR__"xiaosquare");
	ob->move(me->query_temp("gstart_rooms"));
	me->apply_condition("guanfu_task", me->set_temp("guanfu_time", random(70)+20));
	me->apply_condition("guanfu_busy", random(10)+5);
	
	return 1;
}
