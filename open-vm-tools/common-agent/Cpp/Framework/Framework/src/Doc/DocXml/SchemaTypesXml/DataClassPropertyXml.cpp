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

#include "Doc/DocXml/SchemaTypesXml/CmdlMetadataXml.h"

#include "Doc/SchemaTypesDoc/CCmdlMetadataDoc.h"
#include "Doc/SchemaTypesDoc/CDataClassPropertyDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/SchemaTypesXml/DataClassPropertyXml.h"

using namespace Caf;

void DataClassPropertyXml::add(
	const SmartPtrCDataClassPropertyDoc dataClassPropertyDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DataClassPropertyXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(dataClassPropertyDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameVal = dataClassPropertyDoc->getName();
		CAF_CM_VALIDATE_STRING(nameVal);
		thisXml->addAttribute("name", nameVal);

		const std::deque<SmartPtrCCmdlMetadataDoc> cmdlMetadataVal =
			dataClassPropertyDoc->getCmdlMetadata();
		if (! cmdlMetadataVal.empty()) {
			for (TConstIterator<std::deque<SmartPtrCCmdlMetadataDoc> > cmdlMetadataIter(cmdlMetadataVal);
				cmdlMetadataIter; cmdlMetadataIter++) {
				const SmartPtrCXmlElement cmdlMetadataXml =
					thisXml->createAndAddElement("cmdlMetadata");
				CmdlMetadataXml::add(*cmdlMetadataIter, cmdlMetadataXml);
			}
		}

		const std::string valueVal =
			dataClassPropertyDoc->getValue();
		if (! valueVal.empty()) {
			const SmartPtrCXmlElement valueXml =
				thisXml->createAndAddElement("value");
			valueXml->setValue(valueVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCDataClassPropertyDoc DataClassPropertyXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DataClassPropertyXml", "parse");

	SmartPtrCDataClassPropertyDoc dataClassPropertyDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameStrVal =
			thisXml->findRequiredAttribute("name");
		const std::string nameVal = nameStrVal;

		const CXmlElement::SmartPtrCElementCollection cmdlMetadataChildrenXml =
			thisXml->findOptionalChildren("cmdlMetadata");

		std::deque<SmartPtrCCmdlMetadataDoc> cmdlMetadataVal;
		if (! cmdlMetadataChildrenXml.IsNull() && ! cmdlMetadataChildrenXml->empty()) {
			for (TConstIterator<CXmlElement::CElementCollection> cmdlMetadataXmlIter(*cmdlMetadataChildrenXml);
				cmdlMetadataXmlIter; cmdlMetadataXmlIter++) {
				const SmartPtrCXmlElement cmdlMetadataXml = cmdlMetadataXmlIter->second;
				const SmartPtrCCmdlMetadataDoc cmdlMetadataDoc =
					CmdlMetadataXml::parse(cmdlMetadataXml);
				cmdlMetadataVal.push_back(cmdlMetadataDoc);
			}
		}

		const SmartPtrCXmlElement valueXml =
			thisXml->findOptionalChild("value");

		std::string valueVal;
		if (! valueXml.IsNull()) {
			if (! valueXml.IsNull()) {
				valueVal = valueXml->getValue();
			}
		}

		dataClassPropertyDoc.CreateInstance();
		dataClassPropertyDoc->initialize(
			nameVal,
			cmdlMetadataVal,
			valueVal);
	}
	CAF_CM_EXIT;

	return dataClassPropertyDoc;
}
