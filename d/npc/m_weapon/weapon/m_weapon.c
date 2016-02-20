// /d/npc/m_weapon/weapon/m_axe.c
// Modified by Zeratul Jan 13 2001 不能锻炼在地上的自铸武器

#include <ansi.h>
#include <weapon.h>
inherit M_WEAPON; 

int do_hui(object weapon);
string QI,JI,upmsg;
string creat_info(object me,string msg1,int flag);
int do_setwmsg(string arg);
string query_autoload() { return 1 + ""; }	//autoload weapon
void copyto(object ob);

void init()
{
	if (!query("inited")) 
	{
		set("inited",1);
	  copyto(this_player());
	}
  if ( !query("desting") && !environment()->is_character() )
  { 
    	set("desting",1);
    	call_out("dest_me",10,this_object());
  };
	add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
	add_action("do_setwmsg","setwmsg");
}

void copyto(object me)
{
	string w_name,w_id,w_or;
	int w_lv , damage;
	if (!me->query("weapon/make"))
	{
		call_out("destruct",0,this_object());
    return;
  }
  set("inited",1);
//读入数据
	w_name=me->query("weapon/name");
	w_id = me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
	set_name(w_name, ({w_id}));
	set("owner",me->query("id"));
	set("ownmake",1);
	damage = w_lv *10 + me->query("gift/weapon");
	switch (me->query("weapon/type"))
	{
		case "斧":
			set("unit","把");
			set("wield_msg", "$N往腰中一摸，抽出了一把"+w_name+"在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"往身后一别，别在后腰上了。\n");			
			init_axe(damage);
			QI="斧气";
			JI="指斧背";
			upmsg=CYN"斧身忽的一闪，一道银光隐入$N的"+w_name+CYN"中，不见了！\n"NOR;
			break;

		case "杖":
			set("unit","杆");
			set("wield_msg", "$N往背后一摸，掏出了一杆"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"一挥，眨眼间已然不见影踪。\n");			
			init_staff(damage);
			QI="杖体";
			JI="握杖端";
			upmsg=HIY"杖身忽的一亮，一道金光隐入$N的"+w_name+HIY"体，不见了！\n"NOR;
			break;

		case "刀":
			set("unit","柄");
			set("wield_msg", "$N往腰中一抽，拔出了一把"+w_name+"在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"迎风一抖，眨眼间已然不见影踪。\n");
			init_blade(damage);
			QI="刀气";
			JI="指刀脊";
			upmsg=CYN"刀身忽的一闪，一道银光隐入$N的"+w_name+CYN"中，不见了！\n"NOR;
			break;

		case "棍":
			set("unit","根");
			set("wield_msg", "$N往腰中一摸，拿出了一把"+w_name+"，端在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"抖出一个棍花，眨眼间已然不见影踪。\n");
			init_club(damage);
			QI="兵器";
			JI="指棍脊";
			upmsg=HIY"棍身忽的一亮，似乎一种新生的力量在"+w_name+HIY"中涌动起来！\n"NOR;
			break;

		case "锤":
			set("unit","把");
			set("wield_msg", "$N往后腰中一摸，取出了一柄"+w_name+"握在手中。\n");
			set("unwield_msg","$N手中"+w_name+"往腰后一别，眨眼间已然不见影踪。\n");
			init_hammer(damage);
			QI="锤气";
			JI="指锤体";
			upmsg=HIY"锤身忽的一亮，一道金光隐入$N的"+w_name+HIY"体，不见了！\n"NOR;
			break;

		case "钩":
			set("unit","柄");
			set("wield_msg", "$N「唰」的一声抽出一把"+w_name+"握在手中。\n");
			set("unwield_msg", "$N将手中的"+w_name+"一抖，白光一闪，转眼间"+w_name+"已然不见踪影。\n");
			init_hook(damage + 2);
			QI="兵器";
			JI="捏钩尖";
			upmsg=HIY"钩身忽的一亮，一道金光隐入$N的"+w_name+HIY"，不见了！\n"NOR;
			break;

		case "枪":
			set("unit","杆");
			set("wield_msg", "$N往背后一摸，掏出了一杆"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"一挥，眨眼间已然不见影踪。\n");
			init_spear(damage);
			QI="枪体";
			JI="握枪头";
			upmsg=HIY"枪身忽的一亮，一道金光隐入$N的+"+w_name+HIY"体，不见了！\n"NOR;
			break;

		case "棒":
			set("unit","根");
			set("wield_msg", "$N往背后一摸，掏出了一杆"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"一挥，眨眼间已然不见影踪。\n");
			init_stick(damage);
			QI="棒体";
			JI="握棒端";
			upmsg=HIY"棒身忽的一亮，一道金光隐入$N的"+w_name+HIY"体，不见了！\n"NOR;
			break;

		case "剑":
			set("unit","口");
			set("wield_msg", "$N往腰中一带，抽出了一口"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"迎风一抖，眨眼间已然不见影踪。\n");
			init_sword(damage);
			QI="剑气";
			JI="指剑脊";
			upmsg=HIY"剑身忽的一亮，一道金光隐入$N的"+w_name+HIY"体，不见了！\n"NOR;
			break;

		case "鞭":
			set("unit","条");
				set("wield_msg", "$N往腰中一摸，刷的抖出了一条"+w_name+"。\n");
				set("unwield_msg","$N手中"+w_name+"一抖，眨眼间卷回腰间不见了影踪。\n");
			init_whip(damage);
			QI="兵器";
			JI="捏鞭稍";
			upmsg=HIY"鞭身忽的一亮，一道金光隐入$N的"+w_name+HIY"，不见了！\n"NOR;
			break;
			
		default :
			tell_object(me,"你的自铸武器有错，请通知巫师解决。\n");
			call_out("destruct",0,this_object());
			return;
	}
	switch(w_or)
	{
		//普通长剑重量 5000
		//兵器初始硬度rigidity 剑== 伤害/4 其它类型有一点比例差别
		case "千年神木" :
			set_weight(2000);
      			add("rigidity",query("rigidity")/3);
			set("material", "wood");
			break;
		case "海底金母" :
			set_weight(30000);
			set("material", "steel");
			break;
		case "寒丝羽竹" :
			set_weight(30);
      			set("material","softsteel");
			break;
		case "陨星铁石" :
			set_weight(10000);
			add("rigidity",query("rigidity")/2);
			set("material", "iron");
			break;
/*		case "雷火寒晶" :
			set_weight(30000);
			set("material", "golden");  //待开发
*/
		default :
	} 
	set_desc(w_lv,w_or,w_name);
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
  if( me->query("weapon/killed"))
    set("killed", me->query("weapon/killed"));
}

void create()
{	
	set_name("自铸兵器",({"own weapon"}));
	set("no_get",(: this_player()->query("id") != this_object()->query("owner") :));
	set("no_drop",1);
	set("player",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("unit","柄");
	setup();
}	

int do_duanlian(object weapon)
{
	object me = this_player();
	int w_zhi, w_level;
	string w_name, w_or;

	w_name=me->query("weapon/name");
	w_level = (int)me->query("weapon/lv");

	if (me->query("max_neili") < 100 )
		return notify_fail("你内力修为不够，无法锻炼兵器。\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");

	if ( me->is_fighter()) return notify_fail("战斗中无法锻炼！\n");

	if( !weapon || !present( weapon, me ) || query("owner")!=me->query("id"))
		return notify_fail("你要锻炼什么？\n");

	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力不够，无法锻炼"+QI+"！\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("你的气不够，无法锻炼"+QI+"！\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("你现在的体力太弱，无法锻炼"+QI+"！\n");

	if( (int)me->query("jing") < 30 )
			return notify_fail("你现在的精力无法集中，不能锻炼"+QI+"！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("你的潜能不够，无法锻炼"+QI+"！\n");
		
//	if( w_level >= (int)(me->query("int") + me->query("sta"))/2 )
	if(w_level>=(me->query_con()+me->query_sta())/3
//		||w_level>=60  	//上限600伤害  
		)
	{
		message_vision(RED"$N使劲锻炼着"+w_name+RED"，可是好象没什么效果！\n"NOR, me);
		return 1;
	}
	message_vision(HIR "$N手"+JI+"，一股内力丝丝的传了进去。\n" NOR, me);

//	me->start_busy(3);
	me->add("max_neili",-10);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("learned_points", 2);

	w_zhi = (int)me->query("weapon/value");
	w_zhi++;
	me->set("weapon/value", w_zhi);
	w_or = (string)me->query("weapon/or");
	
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("weapon/lv", w_level);
		message_vision(upmsg,me);
		message_vision(HIG"$N的"+w_name+HIG"的等级提高了！\n"NOR, me);
//		weapon=this_object();
//		if(weapon->query("equipped") ) 
//			weapon->unequip();
//		reload_object( weapon );
//		weapon->copyto(me);
		seteuid(getuid());
		weapon=new("/d/npc/m_weapon/weapon/m_weapon");
//		weapon->copyto(me);
		weapon->move(this_player());
		me->set("weapon/value",0);
		destruct(this_object());
		return 1;
	}
	message_vision(RED"$N的"+w_name+RED"的质地改善了！\n"NOR, me);
	return 1;
}

int do_hui(string weapon)
{	
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon || !id(weapon)|| query("owner")!=me->query("id"))
		return 0;
//		return notify_fail("你要摧毁什么？\n");
	message_vision(HIR"$N大喝一声，一掌擎"+me->query("weapon/type")+"，一掌猛力击下。结果轰隆一声巨响"+w_name+HIR"断为两截！\n"NOR,me);
	me->set("weapon/make",0);
//	me->delete("weapon");
	me->save();
	destruct( this_object() );
	return 1;
}

void owner_is_killed()
{
	object piece;
	write(HIY"只见一声清脆的响声，"+query("name")+HIY"落在地上，断成数截。\n"NOR);
	this_object()->unequip();
 	seteuid(getuid());
 	piece = new("/clone/misc/piece");
 	piece->set("long", query("long"));
 	piece->set_name( query("name") + "的碎片", ({query("id"),"piece"}) );
 	if(environment(environment()))
 	  piece->move(environment(environment()));
	destruct(this_object());
}

int do_setwmsg(string info)
{
	int i;
	object me=this_player();
	string msg,command,msg1;
	string *ban_name=({
		"【",		"】",		"仙子",		"风儿",		"巫师",
		"天神",	"告诉",	"回答",
		});
	object weapon;
	if( !info ) return 0;
	if( !(me->query("weapon/make")))
		return notify_fail("你没有自制的兵器！\n");
	if (strsrch(info, "$N") < 0)
		return notify_fail("描述里要有$N表示你自己！\n");
	if (strsrch(info, "$WEAPON$") < 0)
		return notify_fail("描述里要带$WEAPON$表示你的兵器！\n");
	for (i=0;i<sizeof(ban_name);i++)
	if (strsrch(info, ban_name[i]) > 0)
		return notify_fail("描述里出现了非法字符！\n");
	weapon = this_object();
	if( !objectp(weapon) || !present(weapon,me)) 
	return notify_fail("你的兵器不在身边！\n");
	sscanf(info ,"%s %s" ,command ,msg1);
	switch(command)
	{
		case "-w":
			msg = creat_info(me,msg1,1);
			me->set("weapon/wield_msg",msg);
			weapon->set("wield_msg",msg+"\n"NOR);
			break;
		case "-u":
			msg = creat_info(me,msg1,1);
			me->set("weapon/unwield_msg",msg);
			weapon->set("unwield_msg",msg+"\n"NOR);
			break;
		default :
			return notify_fail("描述设置失败，请选择具体参数。详细请
看帮助文件。\n");
	}
	write("Ok.\n");
	return 1;
	}
	
string creat_info(object who,string msg1,int flag)
{
		string w_name,name;
	int w_lv,color;
	w_lv = who->query("weapon/lv");
	w_name = who->query("weapon/name");
	color = (w_lv/10);
	color = w_lv - color*10;
	switch(color){
		case 1:
		case 2:
			name = HIR + w_name + NOR;
			break;
		case 3:
		case 4:
			name = HIG + w_name + NOR;
			break;
		case 5:
		case 6:
			name = HIY + w_name + NOR;
			break;
		case 7:
		case 8:
			name = HIB + w_name + NOR;
			break;
		case 9:
			name = HIM + w_name + NOR;
			break;
		case 0:
			name = HIC + w_name + NOR;
			break;
	}
	if ( flag==2 )
		return name;
	msg1+="$NOR$";
	msg1 = replace_string(msg1, "$WEAPON$",name);
	msg1 = replace_string(msg1, "$BLK$", BLK);
	msg1 = replace_string(msg1, "$RED$", RED);
	msg1 = replace_string(msg1, "$GRN$", GRN);
	msg1 = replace_string(msg1, "$YEL$", YEL);
	msg1 = replace_string(msg1, "$BLU$", BLU);
	msg1 = replace_string(msg1, "$MAG$", MAG);
	msg1 = replace_string(msg1, "$CYN$", CYN);
	msg1 = replace_string(msg1, "$WHT$", WHT);
	msg1 = replace_string(msg1, "$HIR$", HIR);
	msg1 = replace_string(msg1, "$HIG$", HIG);
	msg1 = replace_string(msg1, "$HIY$", HIY);
	msg1 = replace_string(msg1, "$HIB$", HIB);
	msg1 = replace_string(msg1, "$HIM$", HIM);
	msg1 = replace_string(msg1, "$HIC$", HIC);
	msg1 = replace_string(msg1, "$HIW$", HIW);
	msg1 = replace_string(msg1, "$NOR$", NOR);
	if ( flag==1)
		return msg1;
}

void dest_me(object me)
{
	set("desting",0);
	if (!environment(me) || !environment(me)->is_character())
	{
		message_vision("$N慢慢失去灵性，终于化做一堆尘土随风而逝。\n",me);
    destruct(me);
  }
}