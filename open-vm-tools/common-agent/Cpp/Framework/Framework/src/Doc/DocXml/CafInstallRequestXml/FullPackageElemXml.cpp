/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/CafInstallRequestXml/PackageDefnXml.h"

#include "Doc/CafInstallRequestDoc/CFullPackageElemDoc.h"
#include "Doc/CafInstallRequestDoc/CPackageDefnDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/CafInstallRequestXml/FullPackageElemXml.h"

using namespace Caf;

void FullPackageElemXml::add(
	const SmartPtrCFullPackageElemDoc fullPackageElemDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("FullPackageElemXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(fullPackageElemDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string indexVal =
			CStringConv::toString<int32>(fullPackageElemDoc->getIndex());
		CAF_CM_VALIDATE_STRING(indexVal);
		thisXml->addAttribute("index", indexVal);

		const std::string packageNamespaceVal = fullPackageElemDoc->getPackageNamespace();
		CAF_CM_VALIDATE_STRING(packageNamespaceVal);
		thisXml->addAttribute("packageNamespace", packageNamespaceVal);

		const std::string packageNameVal = fullPackageElemDoc->getPackageName();
		CAF_CM_VALIDATE_STRING(packageNameVal);
		thisXml->addAttribute("packageName", packageNameVal);

		const std::string packageVersionVal = fullPackageElemDoc->getPackageVersion();
		CAF_CM_VALIDATE_STRING(packageVersionVal);
		thisXml->addAttribute("packageVersion", packageVersionVal);

		const SmartPtrCPackageDefnDoc installPackageVal =
			fullPackageElemDoc->getInstallPackage();
		CAF_CM_VALIDATE_SMARTPTR(installPackageVal);

		const SmartPtrCXmlElement installPackageXml =
			thisXml->createAndAddElement("installPackage");
		PackageDefnXml::add(installPackageVal, installPackageXml);

		const SmartPtrCPackageDefnDoc uninstallPackageVal =
			fullPackageElemDoc->getUninstallPackage();
		CAF_CM_VALIDATE_SMARTPTR(uninstallPackageVal);

		const SmartPtrCXmlElement uninstallPackageXml =
			thisXml->createAndAddElement("uninstallPackage");
		PackageDefnXml::add(uninstallPackageVal, uninstallPackageXml);
	}
	CAF_CM_EXIT;
}

SmartPtrCFullPackageElemDoc FullPackageElemXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("FullPackageElemXml", "parse");

	SmartPtrCFullPackageElemDoc fullPackageElemDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string indexStrVal =
			thisXml->findRequiredAttribute("index");
		int32 indexVal = 0;
		if (! indexStrVal.empty()) {
			indexVal = CStringConv::fromString<int32>(indexStrVal);
		}

		const std::string packageNamespaceStrVal =
			thisXml->findRequiredAttribute("packageNamespace");
		const std::string packageNamespaceVal = packageNamespaceStrVal;

		const std::string packageNameStrVal =
			thisXml->findRequiredAttribute("packageName");
		const std::string packageNameVal = packageNameStrVal;

		const std::string packageVersionStrVal =
			thisXml->findRequiredAttribute("packageVersion");
		const std::string packageVersionVal = packageVersionStrVal;

		const SmartPtrCXmlElement installPackageXml =
			thisXml->findRequiredChild("installPackage");

		SmartPtrCPackageDefnDoc installPackageVal;
		if (! installPackageXml.IsNull()) {
			installPackageVal = PackageDefnXml::parse(installPackageXml);
		}

		const SmartPtrCXmlElement uninstallPackageXml =
			thisXml->findRequiredChild("uninstallPackage");

		SmartPtrCPackageDefnDoc uninstallPackageVal;
		if (! uninstallPackageXml.IsNull()) {
			uninstallPackageVal = PackageDefnXml::parse(uninstallPackageXml);
		}

		fullPackageElemDoc.CreateInstance();
		fullPackageElemDoc->initialize(
			indexVal,
			packageNamespaceVal,
			packageNameVal,
			packageVersionVal,
			installPackageVal,
			uninstallPackageVal);
	}
	CAF_CM_EXIT;

	return fullPackageElemDoc;
}

